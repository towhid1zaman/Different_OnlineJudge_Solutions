#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 2000001;
const int mod = 1000000007;

struct Combinatorics{
    ll fact[maxn],inv[maxn];
 
    ll BigMod(ll b,ll p,ll m){
        ll ret = 1;
        while(p > 0){
            if(p&1)ret = (ret * b) % m;
            p = p >> 1;
            b = (b * b) % m;
        }
        return ret;
    }
 
    void Build(ll n){
        fact[0] = 1;
        for(int i = 1;i <= n+2;i++){
            fact[i] = (fact[i - 1] * i) % mod;
        }
        for(int i = 0;i <= n+2;i++){
            inv[i] = BigMod(fact[i],mod-2,mod);
        }
    }
 
    ll Choose(ll n,ll r){
        if(n < r)return 0;
        ll u = fact[n];
        ll v = (inv[r] * inv[n - r]) % mod;
        return (u * v) % mod;
    }

    ll Factorial(ll n){
        return fact[n];
    }
    ll Factinv(ll n){
        return inv[n];
    }

}combi;

/*

distribute ncr = (n+m-1)c(m)
*/

void task(){
    ll n, m; cin >> n >> m;
    ll ans = combi.Choose(n+m-1, m);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    combi.Build(maxn);
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
