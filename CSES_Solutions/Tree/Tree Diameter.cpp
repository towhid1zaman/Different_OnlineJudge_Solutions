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
PT07Z - Longest path in a tree

/*
explanation : https://towhid1zaman.blogspot.com/2021/09/the-diameter-of-tree-is-longest-path.html
*/
pair<int, int> mxNode;
std::vector<int> edges[maxn];
void BFS(int root){
    queue<pair<int, int> >Q;
    std::vector<bool> vis(maxn, 0);
    Q.push({root, 0});

    while(!Q.empty()){
        mxNode = Q.front();
        vis[mxNode.first] = 1;
        Q.pop();
        for(int x:edges[mxNode.first]){
            if(vis[x] == 0){
                Q.push({x, mxNode.second + 1});
            }
        }
    }
}
void task(){
    int n; cin >> n;
    for(int i = 2; i<=n; i++){
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    BFS(1);
    BFS(mxNode.first);
    cout << mxNode.second << endl;
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
