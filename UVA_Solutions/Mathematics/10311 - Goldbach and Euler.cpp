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
const int maxn = 100000001;
const int mod = 1000000007;
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbug(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}



/*
 *Optimization
 *1.Use Bitset
 *2.Consider only Odd number
 *3.Check Range Carefully
 */

#define M 100000000
std::vector<int>primes;
int marked[(M>>6) + 2];

#define on(x) (marked[x>>6] & ( 1<<((x>>1)&31 )))
#define mark(x) (marked[x>>6] |= ( 1<<( (x>>1)&31 )))

bool isPrime(int n){
  if(n%2==0 or n<2) return false;
  return !on(n);
}

void sieve(int n){
  for(int i = 3; i*i < n; i+=2){
    if(!on(i)){
      for(int j = i*i; j<=n; j += i+i){
        mark(j);
      }
    }
  }

  primes.push_back(2);
  for(int i = 3; i<=n; i+=2){
    if(isPrime(i)){
      primes.push_back(i);
    }
  }

}

void task(){
    //dbug(primes);
    int n;
    while(cin >> n){
        int another = 0;
        bool ok = 0;
        if(n&1){
          if(isPrime(n-2)){
            cout << n<<" is the sum of "<<2<<" and "<<n-2<<"."<<endl;  
          }
          else cout << n<<" is not the sum of two primes!"<<endl;
        }
        else{
          for(int i = (n>>1)-1; i>=0;i--){
            if(isPrime(i) and isPrime(n-i)){
              cout << n<<" is the sum of "<<i<<" and "<<n-i<<"."<<endl;
              ok = 1;
              break;
            }
          }
          if(!ok)cout << n<<" is not the sum of two primes!"<<endl;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve(M);
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
