/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;


int dp[20000100];
int go(int n){
    if(dp[n]!=-1)return dp[n];
    if(n==1)return 0;

    int ans = go(n-1) + 1;
    if(n%3==0) ans = min(ans, go(n/3) + 1);
    if(n%2==0) ans = min(ans, go(n/2) + 1);

    return dp[n] = ans;
}
void task(){
    int n; cin >> n;
    int ans = go(n);
    cout << ans << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    memset(dp, -1, sizeof(dp));
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
