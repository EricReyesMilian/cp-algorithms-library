int main(){
  mt19937 g(7); int bad=0;
  // suffix array vs naive
  for(int it=0;it<300;it++){ int n=g()%15+1; string s(n,'a'); for(auto&c:s)c='a'+g()%3;
    SuffixArray sa(s); vi nv(n); iota(all(nv),0); sort(all(nv),[&](int a,int b){return s.substr(a)<s.substr(b);});
    if(nv!=sa.sa) bad++;
    sa.build_rmq(); for(int a=0;a<n;a++)for(int b=0;b<n;b++){ int l=0; while(a+l<n&&b+l<n&&s[a+l]==s[b+l])l++; if(a!=b&&sa.lcp_suffix(a,b)!=l) bad++; }
    // z, kmp
    auto z=z_function(s); for(int i=1;i<n;i++){int l=0; while(i+l<n&&s[l]==s[i+l])l++; if(z[i]!=l) bad++;}
    // SAM distinct
    SAM sm; for(char c:s) sm.extend(c); set<string> ss; for(int i=0;i<n;i++)for(int l=1;i+l<=n;l++) ss.insert(s.substr(i,l));
    if((ll)ss.size()!=sm.distinct_substrings()) bad++;
    Eertree et; for(char c:s) et.add(c); set<string> pal; for(string x:ss){ string r=x; reverse(all(r)); if(r==x) pal.insert(x);} if((int)pal.size()!=et.distinct()) bad++;
    // manacher count
    auto [d1,d2]=manacher(s); ll cm=0; for(int i=0;i<n;i++) cm+=d1[i]+d2[i]; ll cn=0; for(int i=0;i<n;i++)for(int l=1;i+l<=n;l++){string x=s.substr(i,l),r=x;reverse(all(r)); cn+=x==r;} if(cm!=cn) bad++;
    // min rotation
    int mr=min_rotation(s); string best=s; for(int i=0;i<n;i++){ string r=s.substr(i)+s.substr(0,i); best=min(best,r);} if(s.substr(mr)+s.substr(0,mr)!=best) bad++;
  }
  // aho
  { AhoCorasick ac; vector<string> ps={"ab","b","aba"}; for(auto&p:ps) ac.add(p); ac.build(); string t="ababab"; ll c=0; for(auto&p:ps) for(size_t i=0;i+p.size()<=t.size();i++) c+=t.substr(i,p.size())==p; if(c!=ac.count_matches(t)) bad++; }
  printf("bad=%d\n",bad);
}
