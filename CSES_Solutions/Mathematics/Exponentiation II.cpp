#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

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
    ll a, b, c; cin >> a >> b >> c;
    ll ans = bigmod(b,c,mod-1);
    ans = bigmod(a,ans,mod);
    cout << ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
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
