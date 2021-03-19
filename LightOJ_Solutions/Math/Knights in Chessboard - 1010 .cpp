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
    ll m, n; cin >> m >> n;
    ll ans = (m*n+1)/2;;
    if(m < 2 or n < 2)ans = max(m, n);
    else if(m==2 or n==2)ans = ((m*n)/8)*4 + (((m*n)%8)>=4 ? 4 : (m*n)%8);
    cout << ans << endl; 
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
