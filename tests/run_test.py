#!/usr/bin/env python3
"""python3 tests/run_test.py stem1,stem2 archivo_main.cpp : compila template + snippets + main de prueba y lo ejecuta."""
import os, sys, subprocess, tempfile
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from build_snippets import collect, resolve, ROOT
items = collect()
tpl = open(os.path.join(ROOT, '00_template', 'template.cpp')).read()
header = tpl[:tpl.index('void solve()')]
seen = set(); body = []
for s in sys.argv[1].split(','):
    body.append(resolve(items, s, seen)) if s not in seen else None
src = header + '\n'.join(body) + '\n' + open(sys.argv[2]).read()
d = tempfile.mkdtemp(); p = d + '/t.cpp'; open(p, 'w').write(src)
r = subprocess.run(['g++', '-std=c++17', '-O1', '-w', p, '-o', d + '/t'], capture_output=True, text=True)
if r.returncode: print(r.stderr[:2000]); sys.exit(1)
r = subprocess.run([d + '/t'], capture_output=True, text=True, timeout=60)
print(r.stdout.strip(), r.stderr.strip()[:500])
