int main(){
  mt19937 g(5); int bad=0;
  for(int it=0;it<200;it++){
    int n=g()%7+2; vector<vi> t(n); for(int i=1;i<n;i++){int p=g()%i; t[i].pb(p); t[p].pb(i);}
    LCA l1(t); LCAFast l2(t); HLD h(n); for(int i=1;i<n;i++) for(int v:t[i]) if(v<i) h.add_edge(i,v); h.build();
    // brute lca by parent chain from l1
    for(int a=0;a<n;a++)for(int b=0;b<n;b++){ int x=l1.lca(a,b); if(l2.lca(a,b)!=x||h.lca(a,b)!=x) bad++; }
    // diameter vs brute dist
    vector<vector<pair<int,ll>>> w(n); for(int i=0;i<n;i++) for(int v:t[i]) w[i].push_back({v,1});
    auto dm=tree_diameter(w); ll mx=0; for(int a=0;a<n;a++)for(int b=0;b<n;b++) mx=max<ll>(mx,l1.dist(a,b)); if(dm[0]!=mx) bad++;
    // rerooting ecc
    Rerooting rr(t); rr.run(); for(int a=0;a<n;a++){ ll e=0; for(int b=0;b<n;b++) e=max<ll>(e,l1.dist(a,b)); if(rr.res[a]!=e) bad++; }
    // centroid: par chain depth <= log
    Centroid c(t); for(int a=0;a<n;a++) if(c.lvl[a]>4) bad++;
    // prufer roundtrip
    if(n>=3){ vector<pii> ed; for(int i=1;i<n;i++) for(int v:t[i]) if(v<i) ed.push_back({i,v}); auto code=prufer_encode(n,ed); auto back=prufer_decode(code); set<pii> A,B; for(auto [u,v]:ed)A.insert({min(u,v),max(u,v)}); for(auto [u,v]:back)B.insert({min(u,v),max(u,v)}); if(A!=B) bad++; }
  }
  // SCC vs reachability, 2sat, bridges
  for(int it=0;it<300;it++){
    int n=g()%7+1,m=g()%12; vector<vi> r(n,vi(n,0)); SCC s(n); SCCK k(n); for(int i=0;i<n;i++) r[i][i]=1;
    for(int i=0;i<m;i++){int u=g()%n,v=g()%n; s.add_edge(u,v); k.add_edge(u,v); r[u][v]=1;}
    for(int q=0;q<n;q++)for(int i=0;i<n;i++)for(int j=0;j<n;j++) if(r[i][q]&&r[q][j]) r[i][j]=1;
    s.run(); k.run();
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){ bool same=r[i][j]&&r[j][i]; if(same!=(s.comp[i]==s.comp[j])) bad++; if(same!=(k.comp[i]==k.comp[j])) bad++; }
  }
  for(int it=0;it<300;it++){
    int n=g()%6+1,m=g()%8; Bridges b(n); vector<pii> E; for(int i=0;i<m;i++){int u=g()%n,v=g()%n; if(u==v) continue; b.add_edge(u,v); E.push_back({u,v});}
    b.run(); auto comps=[&](int skip){ DSU d(n); for(int i=0;i<(int)E.size();i++) if(i!=skip) d.unite(E[i].fi,E[i].se); return d.comps; };
    for(int i=0;i<(int)E.size();i++) if((comps(i)>comps(-1))!=(bool)b.is_bridge[i]) bad++;
    // cut vertices
    for(int v=0;v<n;v++){ DSU d(n); for(auto [x,y]:E) if(x!=v&&y!=v) d.unite(x,y); int c1=0; for(int i=0;i<n;i++) if(i!=v&&d.find(i)==i) c1++; DSU d2(n); for(auto [x,y]:E) d2.unite(x,y); int c0=0; for(int i=0;i<n;i++) if(d2.find(i)==i) c0++; bool cut=c1>c0-(0)-( [&]{ bool iso=true; for(auto [x,y]:E) if(x==v||y==v) iso=false; return iso;}() ); if(cut!=b.is_cut[v]) bad++; }
  }
  for(int it=0;it<300;it++){
    int n=g()%4+1,m=g()%8; TwoSAT ts(n); vector<array<int,4>> cl; for(int i=0;i<m;i++){ int a=g()%n,b=g()%n,va=g()%2,vb=g()%2; ts.add_or(a,va,b,vb); cl.push_back({a,va,b,vb}); }
    bool sat=false; for(int mask=0;mask<(1<<n);mask++){ bool ok=true; for(auto&c:cl) if(!((mask>>c[0]&1)==c[1]||(mask>>c[2]&1)==c[3])) ok=false; if(ok) sat=true; }
    bool r=ts.solve(); if(r!=sat) bad++; if(r) for(auto&c:cl) if(!((ts.val[c[0]]==(bool)c[1])||(ts.val[c[2]]==(bool)c[3]))) bad++;
  }
  // bellman/dijkstra/floyd agree
  for(int it=0;it<200;it++){ int n=g()%6+2,m=g()%12; vector<vector<pair<int,ll>>> gr(n); vector<BFEdge> E; Floyd f(n);
    for(int i=0;i<m;i++){int u=g()%n,v=g()%n; ll w=g()%10; gr[u].push_back({v,w}); E.push_back({u,v,w}); f.add_edge(u,v,w);} f.run();
    auto d=dijkstra(gr,0); auto bf=bellman_ford(n,E,0); for(int i=0;i<n;i++){ if(d[i]!=bf[i]||d[i]!=f.d[0][i]) bad++; } }
  printf("bad=%d\n",bad);
}
