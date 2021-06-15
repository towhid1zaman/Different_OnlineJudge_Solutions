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
const int maxn = 1000006;
const int mod = 1000000007;
struct disjoint{
        int fa[maxn];
        int sz[maxn];
        void Build(int n){
            for(int i = 0; i<=n; i++) fa[i]=i, sz[i] = 1;
        }
        int Find(int x){ 
            return x==fa[x]?x:fa[x]=Find(fa[x]);
        }
        void Union(int a, int b){ 
            a = Find(a), b = Find(b);
            if(a==b)return;
            if(sz[a] < sz[b]) swap(a,b);
            fa[b] = a;
            sz[a] += sz[b];
        }
        int Size(int n){
            return sz[n];
        }
}dsu;
int Pair(int a){
    return (a*(a-1))/2;
}
void task(){
    int N; cin >> N;
    int ans = 0;
    dsu.Build(maxn);
    for(int i = 1; i<=N; i++){
        int u, v; cin >> u >> v;
        int a = dsu.Find(u), b = dsu.Find(b);
        if(a!=b){
            ans -= Pair(dsu.Size(a));
            ans -= Pair(dsu.Size(b));
            ans += Pair(dsu.Size(a) + dsu.Size(b));
        }
        dsu.Union(u, v);
        cout << ans << endl;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; ///cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
