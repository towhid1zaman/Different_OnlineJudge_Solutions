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
const int maxn = 1048576;
const int mod = 1000000007;

vll prime;
bitset<maxn>bs;

void sieve(){
        bs.set();
        prime.pb(2);
        for(ll i = 3; i<=maxn; i+=2){
            if(bs[i]){
                prime.pb(i);
                for(ll j = i*i; j<=maxn; j+=i+i){
                    bs[j] = 0;
                }
            }
        }
}

std::vector<ll>compose(maxn, 0);

void composite_sieve(){
  for(int i = 0; i<prime.size(); i++){
    for(int j = 0; j<prime.size() and prime[i]*prime[j] <= maxn; j++){
      compose[ prime[i]*prime[j] ] = 1;
    }
  }
}
void task(){
    int n;
    while(cin >> n){
      int cnt = 0;
      for(int i = 0; i<n; i++){
        ll a; cin >> a;
        if(compose[ a ] == 1)cnt++;
      }
      cout << cnt << endl;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    composite_sieve();
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
