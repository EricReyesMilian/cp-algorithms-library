int main(){
  mt19937 g(9); int bad=0;
  // matching: HK vs Kuhn vs Dinic vs Blossom(bipartite) ; hungarian vs brute
  for(int it=0;it<300;it++){
    int a=g()%5+1,b=g()%5+1,m=g()%12; HopcroftKarp hk(a,b); Kuhn ku(a,b); Dinic di(a+b+2); Blossom bl(a+b); set<pii> E;
    for(int i=0;i<m;i++){int u=g()%a,v=g()%b; if(E.insert({u,v}).second){ hk.add_edge(u,v); ku.add_edge(u,v); di.add_edge(u,a+v,1); bl.add_edge(u,a+v);} }
    for(int i=0;i<a;i++) di.add_edge(a+b,i,1); for(int j=0;j<b;j++) di.add_edge(a+j,a+b+1,1);
    int x=hk.run(), y=ku.run(), z=di.maxflow(a+b,a+b+1), w=bl.solve(); if(x!=y||x!=z||x!=w) bad++;
    auto [cl,cr]=hk.vertex_cover(); int cv=0; for(bool q:cl)cv+=q; for(bool q:cr)cv+=q; if(cv!=x) bad++; for(auto [u,v]:E) if(!cl[u]&&!cr[v]) bad++;
  }
  for(int it=0;it<200;it++){ int n=g()%5+1,m=n+g()%3; vector<vll> c(n+1,vll(m+1)); for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) c[i][j]=(ll)(g()%20)-5;
    vi asg; ll r=hungarian(c,asg); vi p(m); iota(all(p),1); ll best=INF; sort(all(p)); do{ ll s=0; for(int i=1;i<=n;i++) s+=c[i][p[i-1]]; best=min(best,s);}while(next_permutation(all(p))); if(r!=best) bad++; }
  // mcmf: small assignment equals hungarian-like check by brute on tiny
  for(int it=0;it<100;it++){ int n=g()%4+1; vector<vll> c(n,vll(n)); for(auto&r:c)for(auto&x:r)x=g()%10; MCMF f(2*n+2); for(int i=0;i<n;i++){ f.add_edge(2*n,i,1,0); f.add_edge(n+i,2*n+1,1,0); for(int j=0;j<n;j++) f.add_edge(i,n+j,1,c[i][j]); }
    auto [fl,co]=f.run(2*n,2*n+1); vi p(n); iota(all(p),0); ll best=INF; do{ ll s=0; for(int i=0;i<n;i++) s+=c[i][p[i]]; best=min(best,s);}while(next_permutation(all(p))); if(fl!=n||co!=best) bad++; }
  // stoer-wagner vs brute min cut on small
  for(int it=0;it<100;it++){ int n=g()%5+2; vector<vll> m(n,vll(n,0)); for(int i=0;i<n;i++)for(int j=i+1;j<n;j++) m[i][j]=m[j][i]=g()%5; auto r=stoer_wagner(m); ll best=INF; for(int mask=1;mask<(1<<n)-1;mask++){ ll s=0; for(int i=0;i<n;i++)for(int j=0;j<n;j++) if((mask>>i&1)&&!(mask>>j&1)) s+=m[i][j]; best=min(best,s);} if(r.first!=best) bad++; }
  // euler
  { vector<pii> e={{0,1},{1,2},{2,0},{2,3},{3,2}}; auto p=euler_path(4,e,true); if(p.size()!=6) bad++; vector<pii> e2={{0,1},{1,2},{2,0}}; if(euler_path(3,e2,false).size()!=4) bad++; vector<pii> e3={{0,1},{2,3}}; if(!euler_path(4,e3,false).empty()) bad++; }
  // matrix tree: K4 has 16
  { vector<pii> e; for(int i=0;i<4;i++)for(int j=i+1;j<4;j++) e.push_back({i,j}); if(count_spanning_trees(4,e)!=16) bad++; }
  // manhattan mst vs prim brute
  for(int it=0;it<200;it++){ int n=g()%7+2; vector<pii> ps; for(int i=0;i<n;i++) ps.push_back({(int)(g()%20),(int)(g()%20)}); vector<array<ll,3>> E; for(int i=0;i<n;i++)for(int j=i+1;j<n;j++) E.push_back({abs(ps[i].fi-ps[j].fi)+abs(ps[i].se-ps[j].se),i,j}); if(kruskal(n,E)!=manhattan_mst(ps)) bad++; }
  printf("bad=%d\n",bad);
}
