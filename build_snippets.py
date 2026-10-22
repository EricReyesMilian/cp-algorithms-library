#!/usr/bin/env python3
"""Genera snippets de VSCode (cp.code-snippets) e INDEX.md a partir de los .cpp.

Uso:
  python3 build_snippets.py              # genera cp.code-snippets e INDEX.md aqui
  python3 build_snippets.py --install    # ademas lo copia a la carpeta de snippets de usuario de VSCode
  python3 build_snippets.py --workspace  # ademas lo copia a ./.vscode/ del directorio actual
Cada archivo puede tener cabecera:  // @desc: ...  // @cx: ...  // @deps: otro_archivo
Prefijo del snippet = nombre del archivo. Con deps se generan dos: `nombre` (deps incluidas) y `nombre_nd` (sin deps).
"""
import os, re, json, sys, shutil, platform

ROOT = os.path.dirname(os.path.abspath(__file__))
META = re.compile(r'^//\s*@(\w+):\s*(.*)$')

def parse(path):
    lines = open(path, encoding='utf-8').read().split('\n')
    meta, i = {}, 0
    while i < len(lines) and (META.match(lines[i]) or not lines[i].strip()):
        m = META.match(lines[i])
        if m: meta[m.group(1)] = m.group(2).strip()
        i += 1
    return meta, '\n'.join(lines[i:]).rstrip('\n')

def collect():
    items = {}
    for folder in sorted(os.listdir(ROOT)):
        fp = os.path.join(ROOT, folder)
        if not os.path.isdir(fp) or folder.startswith('.') or folder == 'tests': continue
        for fn in sorted(os.listdir(fp)):
            if fn.endswith('.cpp'):
                stem = fn[:-4]
                meta, body = parse(os.path.join(fp, fn))
                items[stem] = dict(folder=folder, meta=meta, body=body, path=os.path.join(fp, fn))
    return items

def resolve(items, stem, seen=None):
    """Cuerpo con dependencias incluidas (sin duplicar)."""
    seen = set() if seen is None else seen
    parts = []
    for d in [x.strip() for x in items[stem]['meta'].get('deps', '').split(',') if x.strip()]:
        if d not in seen:
            seen.add(d); parts.append(resolve(items, d, seen))
    parts.append(items[stem]['body'])
    return '\n\n'.join(parts)

def esc(line): return line.replace('\\', '\\\\').replace('$', '\\$')

def build():
    items = collect(); snippets = {}
    for stem, it in items.items():
        m = it['meta']; desc = f"[{it['folder']}] {m.get('desc', stem)}" + (f" | {m['cx']}" if m.get('cx', '-') != '-' else '')
        for key, body in [(stem, resolve(items, stem))] + ([(stem + '_nd', it['body'])] if m.get('deps') else []):
            snippets[key] = {"prefix": [key], "body": [esc(l) for l in body.split('\n')], "description": desc}
    return items, snippets

def write_index(items):
    out = ['# Indice de la biblioteca\n']; cur = None
    for stem, it in items.items():
        if it['folder'] != cur:
            cur = it['folder']; out.append(f'\n## {cur}\n\n| Snippet | Descripcion | Complejidad |\n|---|---|---|')
        out.append(f"| `{stem}` | {it['meta'].get('desc', '')} | {it['meta'].get('cx', '')} |")
    open(os.path.join(ROOT, 'INDEX.md'), 'w', encoding='utf-8').write('\n'.join(out) + '\n')

def user_dir():
    s = platform.system()
    if s == 'Linux': return os.path.expanduser('~/.config/Code/User/snippets')
    if s == 'Darwin': return os.path.expanduser('~/Library/Application Support/Code/User/snippets')
    return os.path.join(os.environ.get('APPDATA', ''), 'Code', 'User', 'snippets')

if __name__ == '__main__':
    items, snippets = build()
    target = os.path.join(ROOT, 'cp.code-snippets')
    json.dump(snippets, open(target, 'w', encoding='utf-8'), indent=1, ensure_ascii=False)
    write_index(items)
    print(f'{len(items)} archivos -> {len(snippets)} snippets ({target})')
    for flag, d in (('--install', user_dir()), ('--workspace', os.path.join(os.getcwd(), '.vscode'))):
        if flag in sys.argv:
            os.makedirs(d, exist_ok=True); shutil.copy(target, d); print('copiado a', d)
