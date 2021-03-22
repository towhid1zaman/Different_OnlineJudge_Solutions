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
const int maxn = 20000000;
const int mod = 1000000007;

ll ans(ll n, ll c, ll t){
    return t*(c - t*n);
}
void task(){
    ll n,c; cin >> n >> c;
    if(n==0){
        cout << 0 << endl;
        return;
    }
    ll t = (c/(2*n)), tt = (c/(2*n)) + 1;
    cout << (ans(n,c,t) >= ans(n,c,tt) ? t : tt) << endl;
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
        cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
