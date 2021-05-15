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
bitset<1000010>bs;

void sieve(){
        bs.set();
        prime.pb(2LL);
        for(ll i = 3; i<=1000010; i+=2){
            if(bs[i]){
                prime.pb(i);
                for(ll j = i*i; j<=1000010; j+=i+i){
                    bs[j] = 0;
                }
            }
        }
}

ll divisor(ll n){
    if(n==0)return 0;
    //while(n%2==0)n/=2;
    if(n==1)return 1;
    ll ans = 1;
    for(ll i = 0; i<prime.size() and prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            ll cnt = 0;
            while(n%prime[i]==0){
                if(prime[i]!=2)cnt++;
                n/=prime[i];
            }
            ans*=(cnt+1);
        }
    }
    if(n > 1)ans*=2;
    return ans;
}
void task(){
    ll n;
    while(cin >> n){
      cout << divisor(n) << endl;
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
