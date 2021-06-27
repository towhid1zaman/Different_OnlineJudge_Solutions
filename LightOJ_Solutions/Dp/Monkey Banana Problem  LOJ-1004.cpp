/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;


void task(){
    int n; cin >> n;
    std::vector<vector<int>>dp(2*n+1, vector<int>(2*n+1, 0));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cin >> dp[i][j];
            dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    for(int i = n+1, m = n-1; i<2*n; i++, m--){
        for(int j = 1; j<=m; j++){
            cin >> dp[i][j];
            dp[i][j] += max(dp[i-1][j], dp[i-1][j+1]);
        }
    }
    /*for(int i = 0; i<=2*n; i++){
        for(int j = 0; j<=2*n; j++){
            cout << dp[i][j]<<' ';
        }
        cout << endl;
    }*/
    cout << dp[2*n-1][1] << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
       // cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
