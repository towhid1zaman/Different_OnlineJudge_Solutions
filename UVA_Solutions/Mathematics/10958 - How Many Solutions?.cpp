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

vll prime;
bitset<10000010>bs;

void sieve(){
        bs.set();
        prime.pb(2LL);
        for(ll i = 3; i<=10000000; i+=2){
            if(bs[i]){
                prime.pb(i);
                for(ll j = i*i; j<=10000000; j+=i+i){
                    bs[j] = 0;
                }
            }
        }
}
//DivisorCount using primefactorization
ll divisor(ll n){
    ll ans = 1;
    for(ll i = 0; i<prime.size() and prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            ll cnt = 0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            ans*=(cnt+1);
        }
    }
    if(n!=1)ans*=2;
    return ans;
}
int cnt = 1;
void task(){
   ll m, n, p;
   while(cin >> m >> n >> p and (m and n and p)){
      ll now = (m*n*p*p);
      if(now < 0)now*=-1;
      ll ans = divisor(now)*2;
      cout <<"Case "<<cnt++<<": ";
      cout << ans -1 << endl;
   } 
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
