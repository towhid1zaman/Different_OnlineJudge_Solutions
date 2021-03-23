/*
これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました
*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
#define endl "\n"
#define pb push_back
#define rep(i,a) for(int i=0;i<a;i++)
#define all(v) (v).begin(),(v).end()
const int maxn = 200005;
const int mod = 1000000007;

void task(){
    ll n, q; cin >> n >> q;
    std::vector<ll>a(n);
    rep(i, n){
        cin >> a[i];
    }
    ll res = 0;
    for(ll i = 1; i<n; i++){
        res += (a[i-1] * (n-i));
        res -= (a[n-i] * (n-i));
    }
    while(q--){
        int type; cin >> type;
        if(type == 1){
            cout << res << endl;
        }
        else{
            ll r, v; cin >> r >> v;
            res+= ((n-r-1) * v);
            res-=(r* v);
            res-= ((n-r-1) * a[r]);
            res+=(r * a[r]);
            a[r] = v;
        }
    }
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
        cout <<"Case "<<__<<":"<<endl;
        task();
    }
      
return 0;
}
