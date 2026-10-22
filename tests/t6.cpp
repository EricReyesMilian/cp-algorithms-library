int main(){
  mt19937 g(11); int bad=0;
  for(int it=0;it<300;it++){
    int n=g()%8+3; vector<P> v; for(int i=0;i<n;i++) v.push_back(P(g()%15,g()%15));
    auto h=convex_hull(v);
    // all points inside hull (inclusive); hull strictly convex
    if(h.size()>=3){ if(polygon_area2(h)<=0) bad++; for(auto&p:v) if(!in_convex(h,p)) bad++; for(auto&p:v){ int r=in_polygon(h,p); if(r==0) bad++; } }
    // closest pair
    set<P> st(v.begin(),v.end()); if(st.size()==v.size() && v.size()>1){ auto cp=closest_pair(v); ll best=LLONG_MAX; for(int i=0;i<n;i++)for(int j=i+1;j<n;j++) best=min(best,(v[i]-v[j]).dist2()); if((cp.first-cp.second).dist2()!=best) bad++; }
    // diameter
    if(h.size()>=3){ auto d=hull_diameter(h); ll best=0; for(auto&a:h)for(auto&b:h) best=max(best,(a-b).dist2()); if((d[0]-d[1]).dist2()!=best) bad++; }
  }
  // rect union
  for(int it=0;it<200;it++){ int k=g()%4+1; vector<array<ll,4>> r; set<pii> cells; for(int i=0;i<k;i++){ ll x1=g()%8,y1=g()%8,x2=x1+1+g()%5,y2=y1+1+g()%5; r.push_back({x1,y1,x2,y2}); for(ll x=x1;x<x2;x++)for(ll y=y1;y<y2;y++) cells.insert({x,y}); } if(rect_union_area(r)!=(ll)cells.size()) bad++; }
  // minkowski area check: square + square
  { vector<P> a={P(0,0),P(1,0),P(1,1),P(0,1)}, b={P(0,0),P(2,0),P(2,2),P(0,2)}; auto m=minkowski(a,b); if(polygon_area2(m)!=18) bad++; }
  // seg inter
  { auto r=seg_inter(P(0,0),P(4,4),P(0,4),P(4,0)); if(r.size()!=1) bad++; r=seg_inter(P(0,0),P(1,1),P(2,2),P(3,3)); if(!r.empty()) bad++; }
  // angle sort
  { vector<P> v={P(-1,0),P(0,1),P(1,0),P(0,-1)}; sort(all(v),angle_cmp); if(!(v[0]==P(1,0)&&v[1]==P(0,1)&&v[2]==P(-1,0)&&v[3]==P(0,-1))) bad++; }
  printf("bad=%d\n",bad);
}
