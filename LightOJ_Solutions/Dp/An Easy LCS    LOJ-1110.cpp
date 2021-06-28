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
const int maxn = 101;
const int mod = 1000000007;

string s, t;
string dp[maxn][maxn];
string mn(string a, string b){
    if(a.size() == b.size())return min(a, b);
    if(a.size() > b.size())return a;
    else return b;
}
void task(){
    int n, m;
    cin >> s; n = (int)s.size();
    cin >> t; m = (int)t.size();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = mn(dp[i-1][j], dp[i][j-1]);
            if(s[i-1] ==  t[j-1]) dp[i][j] = mn(dp[i][j], dp[i-1][j-1] + s[i-1]);
        }
    }
    string ans = dp[n][m];
    if(ans.empty())cout << ":(" << endl;
    else cout << ans << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
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
