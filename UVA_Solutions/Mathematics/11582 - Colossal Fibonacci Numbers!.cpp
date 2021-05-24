/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
#define endl "\n"
#define pb push_back
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define all(v) (v).begin(),(v).end()

const double pi = acos(-1.0);
const int maxn = 10000 + 10;
//const int mod = 1000000007;

ll fib[maxn];
ll cycle(ll n){
    fib[0] = 0, fib[1] = 1%n;
    fib[2] = (fib[0] + fib[1])%n;
    for(ll i = 3; i<maxn; i++){
        fib[i] = (fib[i-1] + fib[i-2])%n;
        if(fib[i] == fib[1] and fib[i-1] == fib[0]){
            //cycle found 
            return i-1;
        }
    }
    return 1;
}
        
ll bigmod(ll a, ll e, ll m) {
    ll ret = 1LL;
    ll aa = (ll)a;
    while (e) {
        if (e&1) {
            ret *= aa;
            if (ret > m)
                ret %= m;
            e--;
        }
        aa *= aa;
        e /= 2;
        if (aa > m)
            aa %= m;
    }
    return ret;
}


void task(){
    
    ll a, b, n;
    cin >> a >> b >> n;
    ll cy = cycle(n);
    ll pos = bigmod(a%cy, b, cy);
    cout << fib[pos] << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
