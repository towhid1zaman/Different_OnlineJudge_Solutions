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
const int maxn = 2000006;
const int mod = 1000000007;
int n, m;

int dp[1111][1111];
int go(int n, int m){
    if(dp[n][m] != -1)return dp[n][m];
    if(n<1 and m<1)return 0;
    if(n==1 and m==1)return 1;
    int a = go(n-1, m);
    int b = go(n, m-1);
    if(a < 0)a = 0;
    if(b < 0)b = 0;
    a%=mod; b%=mod;
    return dp[n][m] = (a+b)%mod;
}
void task(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            char c; cin >> c;
            if(c=='.')dp[i][j] = -1;
            else dp[i][j] = -mod;
        }
    }    

    int ans = go(n, m);
    cout << ans << endl;
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
