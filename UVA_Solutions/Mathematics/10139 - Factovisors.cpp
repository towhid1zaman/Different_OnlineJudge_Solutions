/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
#define endl "\n"
#define pb push_back
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define all(v) (v).begin(),(v).end()

const double pi = acos(-1.0);
const int maxn = 200005;
const int mod = 1000000007;


namespace Number_Theory{
    //GCD LCM
    ll gcd(ll a,ll b){
        return b ? gcd(b,a%b) : a;
    }
    ll lcm(ll a, ll b){
        return a/ gcd(a,b)*b;
    }

    //Check Prime
    bool isprime(ll n) { 
        if (n <= 1) return false; 
        if (n <= 3) return true; 
        if (n % 2 == 0 || n % 3 == 0) return false; 
        for (ll i = 5; i * i <= n; i += 6){ 
            if (n % i == 0 || n % (i+2) == 0){
                return false;
            } 
        }
        return true; 
    }

    //sieve, before use it call generate function
    bool prime[21474836]; 
    void sieve(int n) { 
      for (ll i = 0; i <= n; i++) prime[i] = 1;
      for (ll p = 2; p * p <= n; p++) { 
        if (prime[p] == true) { 
          for (ll i = p * p; i <= n; i += p) 
            prime[i] = false; 
        } 
      } 
      prime[1] = prime[0] = 0;
    }

    std::vector<ll>primelist;
    bool prime_generated = 0;

    void GenPrimes(int n){
        prime_generated = 1;
        sieve(n+1);
        for(ll i = 2; i<=n; i++){
            if (prime[i]) primelist.push_back(i);
        }
    }
    // prime factors
    std::vector<ll>factors(ll n) {
    if (!prime_generated) {
        cerr << "Call GenPrimes(int n) first" << endl;
        exit(1);
    }
    std::vector<ll> facs;
        for(ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
            if (n % primelist[i] == 0) {
              while (n % primelist[i] == 0) {
              n /= primelist[i];
              facs.push_back(primelist[i]);
              }
            }
        }
        if (n > 1) {
            facs.push_back(n);
        }
        sort(facs.begin(), facs.end());
        return facs;
    }

    //smallest prime factor
    ll lp[10000005];
    void Smallest_prime_factor(){
        fill(lp, lp+10000005, 0);
        for(ll i=2;i<=10000000;i++){
            if(lp[i]==0)
            for(ll j=i*i;j<=10000000;j+=i){
                if(lp[j]==0)
                lp[j]=i;
            }
            if(lp[i]==0)lp[i]=i;
        }
    }

    // Divisor count sieve
    ll Divisors[10000005];
    void divisor_count(){
        for(ll i = 2; i<10000005; i++){
            if(Divisors[i])continue;
            for(ll j = i; j<10000005; j+=i){
                Divisors[j]++;
            }
        }
    }

    //DivisorCount using primefactorization
    ll divisor(ll n){
        if(!prime_generated){
            cerr << "Call GenPrimes(int n) first" << endl;
            exit(1);
        }
        ll ans = 1;
        for(ll i = 0; i<primelist.size() and primelist[i]*primelist[i]<=n; i++){
            if(n%primelist[i]==0){
                ll cnt = 0;
                while(n%primelist[i]==0){
                    n/=primelist[i];
                    cnt++;
                }
                ans*=(cnt+1);
            }
        }
        if(n!=1)ans*=2;
        return ans;
    }
    //All divisors of a number
    std::vector<ll>getdivs(ll n){
      std::vector<ll>divs;
        for(ll i = 1; i * i <= n; i++) {
          if (n % i == 0) {
            divs.push_back(i);
            if(i != (n/i))divs.push_back(n/i);
          }
      }
      sort(divs.begin(), divs.end());
      return divs;
    }
    ll sum_0f_divisors(ll n){
      if(!prime_generated){
          cerr << "Call GenPrimes(int n) first" << endl;
          exit(1);
      }
      ll oo = n;
      ll ans = 1;
      for(ll i = 0; i<primelist.size() and (ll)primelist[i]*primelist[i]<=n; i++){
          int cnt = 0;
          ll sum = 1, pw = 1;
          while(n%primelist[i]==0){
              pw*=primelist[i];
              sum+=pw;
              cnt++;
              n/=primelist[i];
          }
          if(cnt>0) ans*=sum;
      }
      if(n>1)ans*=n+1;
      return ans - oo; //less than n
  }
}using namespace Number_Theory;

template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbug(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}


void task(){
    ll n, m;
    while(cin >> n >> m){
    std::map<ll,ll> mM;
    mM.clear();
    if(m == 0){
      cout << m <<" does not divide "<<n<<"!"<<endl; 
      continue;
    }
    vll f = factors(m);
    for(auto x:f)mM[x]++;
    bool ok = 1;
    for(auto x:mM){
      ll p = x.first;
      ll puw = x.second;
      ll X = n;
      ll cnt = 0;
      while(X)X/=p, cnt+=X;
      if(puw > cnt)ok = 0;
    }
    
    if(ok){
      cout << m <<" divides "<<n<<"!"<<endl;
    }
    else cout << m <<" does not divide "<<n<<"!"<<endl; 
  }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    GenPrimes(100000);
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
