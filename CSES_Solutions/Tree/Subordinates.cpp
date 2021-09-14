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

/*
Explanation: https://towhid1zaman.blogspot.com/2021/09/in-time-out-time-ancestor-subtree-size.html

*/

int sec = 0;
std::vector<int> edges[maxn], in(maxn, 0), out(maxn, 0);
void dfs(int root, int parent){
    in[root] = ++sec;
    for(auto x: edges[root]){
        if(x!=parent){
            dfs(x, root);
        }
    }
    out[root] = ++sec;
}
void task(){
    int n, m; cin >> n;
    for(int i = 2; i<=n; i++){
        int a; cin >> a;
        edges[a].push_back(i);
        edges[i].push_back(a);
    }
    dfs(1, -1);
    //subtree size
    for(int v = 1; v<=n; v++){
        int sub_size = (out[v] - in[v])/2;
        cout << sub_size<<' ';
    }
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
