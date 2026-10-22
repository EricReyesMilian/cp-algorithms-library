int main(){
  mt19937 g(13); int bad=0;
  for(int it=0;it<200;it++){ Treap t; vector<ll> v; for(int q=0;q<40;q++){ int op=g()%4; int n=v.size();
    if(op==0||n==0){ int p=g()%(n+1); ll x=g()%100; t.insert(p,x); v.insert(v.begin()+p,x);} 
    else if(op==1){ int p=g()%n; t.erase(p); v.erase(v.begin()+p);} 
    else { int l=g()%n,r=l+1+g()%(n-l); if(op==2){ t.reverse_range(l,r); reverse(v.begin()+l,v.begin()+r);} else if(t.range_sum(l,r)!=accumulate(v.begin()+l,v.begin()+r,0LL)) bad++; } }
    if(t.size()!=(int)v.size()) bad++; }
  for(int it=0;it<200;it++){ LineContainer lc; LiChao li(-50,50); vector<pll> L; for(int i=0;i<8;i++){ ll k=(ll)(g()%21)-10,m=(ll)(g()%101)-50; lc.add(k,m); li.insert_line(-k,-m); L.push_back({k,m}); }
    for(ll x=-50;x<=50;x+=7){ ll b=LLONG_MIN; for(auto [k,m]:L) b=max(b,k*x+m); if(lc.query(x)!=b) bad++; if(-li.query(x)!=b) bad++; } }
  for(int it=0;it<300;it++){ int n=g()%10+1; vi a(n); for(auto&x:a)x=g()%6; auto r=lis(a,true); for(int i=1;i<(int)r.size();i++) if(!(r[i-1]<r[i]&&a[r[i-1]]<a[r[i]])) bad++; int best=0; for(int m=0;m<(1<<n);m++){ int last=-1,c=0; bool ok=true; for(int i=0;i<n;i++) if(m>>i&1){ if(a[i]<=last){ok=false;break;} last=a[i];c++;} if(ok) best=max(best,c);} if((int)r.size()!=best) bad++; }
  for(int it=0;it<200;it++){ XorBasis b; vll v; for(int i=0;i<5;i++){ ll x=g()%64; v.push_back(x); b.insert(x);} set<ll> sp={0}; for(ll x:v){ set<ll> ns=sp; for(ll y:sp) ns.insert(y^x); sp=ns;} if(b.max_xor()!=*sp.rbegin()) bad++; if(1LL<<b.rank_!=(ll)sp.size()) bad++; vll sorted(sp.begin(),sp.end()); for(int k=0;k<(int)sorted.size();k++) if(b.kth_smallest(k)!=sorted[k]) bad++; }
  for(int it=0;it<100;it++){ int n=g()%8+1; vll a(n); for(auto&x:a)x=g()%7; ll T=g()%20; ll c=0; for(int m=0;m<(1<<n);m++){ ll s=0; for(int i=0;i<n;i++) if(m>>i&1) s+=a[i]; c+=s<=T;} if(c!=count_subsets_le(a,T)) bad++; }
  for(int it=0;it<100;it++){ int n=g()%8+1; vi a(n); iota(all(a),0); shuffle(all(a),g); ll inv=0; for(int i=0;i<n;i++)for(int j=i+1;j<n;j++) inv+=a[i]>a[j]; if(inv!=count_inversions(a)) bad++; }
  { if(digit_count(1000,5)!=[&]{ll c=0; for(int x=0;x<=1000;x++){int s=0,y=x; while(y){s+=y%10;y/=10;} c+=s==5;} return c;}()) bad++; }
  { if(knuth_merge({3,4,5,1})!=[&]{ vll a={3,4,5,1}; ll best=INF; // brute via interval dp
      int n=4; vector<vll> dp(n,vll(n,0)); for(int len=2;len<=n;len++)for(int l=0;l+len<=n;l++){int r=l+len-1; dp[l][r]=INF; ll s=0; for(int i=l;i<=r;i++)s+=a[i]; for(int k=l;k<r;k++) dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+s);} return dp[0][n-1];}()) bad++; }
  { vector<vll> d={{INF,1,5,9},{2,INF,3,4},{5,3,INF,1},{7,4,2,INF}}; if(tsp(d)<=0||tsp(d)>=INF) bad++; }
  printf("bad=%d\n",bad);
}
