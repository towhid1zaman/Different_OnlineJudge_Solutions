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
    
    
    
#define M 20000000
std::vector<int>primelist;
int marked[(M>>5) + 2];

#define on(x) (marked[x>>5] & ( 1<<((x>>1)&31 )))
#define mark(x) (marked[x>>5] |= ( 1<<( (x>>1)&31 )))

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

  primelist.push_back(2);
  for(int i = 3; i<=n; i+=2){
    if(isPrime(i)){
      primelist.push_back(i);
    }
  }

}

ll divisor(ll n){
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
int tc = 1;
void task(){
    ll c; 
    while(cin >> c and c){
      ll res = divisor((4*c) - 3);
      cout << c << ' '<<res << endl;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //GenPrimes(10000000);
    sieve(M);
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
