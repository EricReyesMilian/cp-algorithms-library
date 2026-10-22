int main(){
  mt19937 g(1); int bad=0;
  for(int it=0;it<300;it++){
    int n=g()%20+1; vector<ll> a(n); for(auto&x:a)x=(int)(g()%100)-50;
    SegTree st(a); Fenwick<ll> fw(n); for(int i=0;i<n;i++) fw.add(i,a[i]);
    DisjointSparse ds(a); vector<int> ai(a.begin(),a.end()); SparseTable<int> sp(ai);
    FenwickRange<ll> fr(n); LazySeg lz(n); lz.build(a);
    vector<ll> b=a; for(int i=0;i<n;i++) fr.add(i,i,a[i]);
    for(int q=0;q<30;q++){
      int l=g()%n,r=g()%n; if(l>r)swap(l,r); ll s=0; int mn=INT_MAX; for(int i=l;i<=r;i++){s+=b[i]; mn=min(mn,(int)a[i]);}
      if(st.query(l,r+1)!=accumulate(a.begin()+l,a.begin()+r+1,0LL)) bad++;
      if(fw.query(l,r)!=accumulate(a.begin()+l,a.begin()+r+1,0LL)) bad++;
      if(ds.query(l,r)!=accumulate(a.begin()+l,a.begin()+r+1,0LL)) bad++;
      if(sp.query(l,r)!=mn) bad++;
      if(fr.query(l,r)!=s) bad++; if(lz.query(l,r+1)!=s) bad++;
      ll v=(int)(g()%21)-10; for(int i=l;i<=r;i++) b[i]+=v; fr.add(l,r,v); lz.update(l,r+1,v);
      // reset point structs consistency not needed
    }
  }
  printf("bad=%d\n",bad);
}
