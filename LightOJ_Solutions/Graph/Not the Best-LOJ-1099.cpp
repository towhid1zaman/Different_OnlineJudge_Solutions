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
#define unq(v) sort(all(v)),v.erase(unique(all(v)),vec.end());
const double pi = acos(-1.0);
const int maxn = 2000006;
const int mod = 1000000007;


void task(){
    int N, R; cin >> N >> R;
    std::vector<pair<int, int>> adj[N+1];
    for(int i = 0; i<R; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Dijkstra

    priority_queue< pair<int, int>,vector< pair<int, int> >,greater< pair<int, int>> > pq;
    vector<int>visit(N+1, 0);
    set<int>distance;

    pq.push({0, 1});
    if(N == 1)distance.insert(0);

    while(!pq.empty()){
        int parent = pq.top().second;
        int parentCost = pq.top().first;

        pq.pop();

        visit[parent]++;
        if(visit[parent] > 3)continue;

        for(auto edge:adj[parent]){
            int child = edge.first;
            int childCost =  edge.second;

            if(visit[child] < 3){
                pq.push({childCost + parentCost, child});
            }

            if(child == N){
                distance.insert(childCost + parentCost);
            }
        }
    }

    auto it = distance.begin();
    it++;
    cout << *it << endl;
}
 
int main(){
    //ctrl+alt+b
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
