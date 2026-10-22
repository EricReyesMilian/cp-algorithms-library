#!/usr/bin/env python3
"""Compila cada archivo (template + deps + archivo + main vacio) con g++ -fsyntax-only para detectar errores."""
import os, subprocess, sys, tempfile
from concurrent.futures import ThreadPoolExecutor
from build_snippets import collect, resolve, ROOT

items = collect()
tpl = open(os.path.join(ROOT, '00_template', 'template.cpp')).read()
header = tpl[:tpl.index('void solve()')]
std = next((a for a in sys.argv[1:] if a.startswith('-std=')), '-std=c++17')

def check(stem):
    if items[stem]['folder'] == '00_template': return stem, None
    src = header + '\n' + resolve(items, stem) + '\n\nint main() {}\n'
    with tempfile.NamedTemporaryFile('w', suffix='.cpp', delete=False) as f: f.write(src); p = f.name
    r = subprocess.run(['g++', std, '-fsyntax-only', '-w', p], capture_output=True, text=True)
    os.unlink(p)
    return stem, (r.stderr if r.returncode else None)

bad = 0
with ThreadPoolExecutor(8) as ex:
    for stem, err in ex.map(check, items):
        if err: bad += 1; print(f'--- ERROR en {stem}\n{err[:1500]}')
print(f'{len(items)} archivos, {bad} con errores')
sys.exit(1 if bad else 0)
