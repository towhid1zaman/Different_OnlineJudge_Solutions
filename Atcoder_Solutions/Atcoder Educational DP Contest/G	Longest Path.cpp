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


std::vector<int>adj[maxn];
std::vector<int>dp(maxn, 0), vis(maxn, 0);

void dfs(int u){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v])dfs(v);
        dp[u] = max(dp[u], dp[v]+1);
    }
}
void task(){
    int n, m; cin >> n >> m;
    for(int i = 1; i<=m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        dfs(i);
    }
    for(int i = 1; i<=n; i++){
        ans = max(ans, dp[i]);
    }
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
