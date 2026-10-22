int main(){
  mt19937 g(3); int bad=0;
  // NTT vs naive
  for(int it=0;it<50;it++){ int n=g()%20+1,m=g()%20+1; vector<int> a(n),b(m); for(auto&x:a)x=g()%NTT::P; for(auto&x:b)x=g()%NTT::P;
    auto c=NTT::multiply(a,b); vector<ll> d(n+m-1); for(int i=0;i<n;i++)for(int j=0;j<m;j++) d[i+j]=(d[i+j]+(ll)a[i]*b[j])%NTT::P; for(int i=0;i<n+m-1;i++) if(c[i]!=d[i]) bad++; }
  // fft conv_mod
  for(int it=0;it<30;it++){ int n=g()%30+1,m=g()%30+1; vll a(n),b(m); for(auto&x:a)x=g()%MOD; for(auto&x:b)x=g()%MOD; auto c=conv_mod<MOD>(a,b); vll d(n+m-1); for(int i=0;i<n;i++)for(int j=0;j<m;j++) d[i+j]=(d[i+j]+a[i]*b[j])%MOD; if(c!=d) bad++; }
  // miller rabin / factorize
  for(ull x=1;x<3000;x++){ bool p=x>=2; for(ull d=2;d*d<=x;d++) if(x%d==0)p=false; if(is_prime(x)!=p) bad++; }
  for(int it=0;it<200;it++){ ull x=g()%1000000000000ULL+2; auto f=factorize(x); ull pr=1; for(auto q:f){ if(!is_prime(q)) bad++; pr*=q;} if(pr!=x) bad++; }
  ull big=1000000007ULL*998244353ULL; auto f=factorize(big); if(f.size()!=2) bad++;
  // fwht xor
  { vll a={1,2,3,4},b={5,6,7,8}; auto c=bit_convolution(a,b,0); vll d(4); for(int i=0;i<4;i++)for(int j=0;j<4;j++) d[i^j]+=a[i]*b[j]; if(c!=d) bad++; 
    c=bit_convolution(a,b,1); vll e(4); for(int i=0;i<4;i++)for(int j=0;j<4;j++) e[i|j]+=a[i]*b[j]; if(c!=e) bad++;
    c=bit_convolution(a,b,2); vll h(4); for(int i=0;i<4;i++)for(int j=0;j<4;j++) h[i&j]+=a[i]*b[j]; if(c!=h) bad++; }
  // floor_sum
  for(int it=0;it<200;it++){ ll n=g()%20,m=g()%20+1,a=(ll)(g()%40)-20,b=(ll)(g()%40)-20; ll s=0; for(ll i=0;i<n;i++) s+=floor_div(a*i+b,m); if(s!=floor_sum(n,m,a,b)) bad++; }
  // crt
  for(int it=0;it<300;it++){ ll m1=g()%12+1,m2=g()%12+1,a1=g()%m1,a2=g()%m2; auto r=crt(a1,m1,a2,m2); bool ex=false; ll L=m1/__gcd(m1,m2)*m2; for(ll x=0;x<L;x++) if(x%m1==a1&&x%m2==a2){ex=true; if(r.first!=x) bad++;} if(!ex&&r.first!=-1) bad++; }
  // discrete log, sqrt mod, primitive root
  for(ll m=2;m<40;m++) for(ll a=0;a<m;a++) for(ll b=0;b<m;b++){ ll ans=-1,cur=1%m; for(ll x=0;x<=2*m+2;x++){ if(cur==b){ans=x;break;} cur=cur*a%m;} if(discrete_log(a,b,m)!=ans) bad++; }
  for(ll p:{7LL,13LL,17LL,998244353LL}) for(ll a=0;a<min(p,50LL);a++){ ll r=sqrt_mod(a,p); if(r>=0&&r*r%p!=a%p) bad++; }
  { ll gr=primitive_root(998244353); if(gr!=3) bad++; }
  // berlekamp + linear_rec fibonacci
  { vll s={1,1}; for(int i=2;i<30;i++) s.push_back((s[i-1]+s[i-2])%MOD); auto c=berlekamp_massey(s); if(c!=vll({1,1})) bad++; if(linear_rec(s,c,29)!=s[29]) bad++; if(linear_rec(vll(s.begin(),s.begin()+2),c,1000000)==0) bad++; }
  printf("bad=%d\n",bad);
}
