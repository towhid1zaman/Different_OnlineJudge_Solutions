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

std::vector<vector<ll>>dp(111, vector<ll>(100005, -1));
std::vector<ll> weight(maxn), value(maxn);

ll go(ll n, ll w){
    if(n <= 0 or w <= 0)return 0;
    ll &ans = dp[n][w];
    if(ans!=-1) return ans;
    ans = 0;
    if(weight[n-1] <= w){
        return ans = max(go(n-1, w - weight[n-1]) + value[n-1], go(n-1, w) ); // take and dont take
    }
    else if(weight[n-1] > w){
        return ans = go(n-1, w); // dont take
    }
}
void task(){
    ll n, w; cin >> n >> w;
    for(int i = 0; i<n; i++){
        cin >> weight[i] >> value[i];
    }
    go(n, w);

    cout << dp[n][w] << endl;
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
