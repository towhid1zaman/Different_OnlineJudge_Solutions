#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const ll maxn = 1000001;
const ll mod = 1000000007;

// example : http://p.ip.fi/Hr6-

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
        for(int i = 1;i <= n;i++){
            fact[i] = (fact[i - 1] * i) % mod;
        }
        for(int i = 0;i <= n;i++){
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

}combi;
void task(){
    ll a, b; cin >> a >> b;
    cout << combi.Choose(a, b) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    combi.Build(maxn);
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
