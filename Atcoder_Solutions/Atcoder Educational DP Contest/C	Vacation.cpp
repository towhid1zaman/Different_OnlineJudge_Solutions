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

void task(){
    int n; cin >> n;
    std::vector<int>dp(3);
    for(int i = 0; i<n; i++){
        std::vector<int>abc(3, 0), new_dp(3, 0);
        for(int j = 0; j<3; j++){
            cin >> abc[j];
        }

        for(int k = 0; k < 3; k++){
            for(int j = 0; j<3; j++){
                if (k!=j){
                    new_dp[j] = max(new_dp[j], dp[k] + abc[j]);
                }
            }
        }
        dp = new_dp;
    }
    sort(all(dp));
    cout << dp[2] << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
