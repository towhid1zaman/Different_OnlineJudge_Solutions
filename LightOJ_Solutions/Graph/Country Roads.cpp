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
const int maxn = 555;
const int mod = 1000000007;

vector< pair<int, int> > adj[maxn];
void init() {
	for (register int i = 0; i < maxn; i++) {
		adj[i].clear();
	}
}
vector<int> dijkstra(int source) {
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq; // minimum priority queue
	vector<int>distance(maxn, -1);
	vector<int>visit(maxn, false);

	distance[source] = 0;

	pq.push({ 0, source });

	while (!pq.empty()) {
		int parent = pq.top().second;
		pq.pop();

		if (visit[parent])continue;
		visit[parent] = true;

		for (auto v : adj[parent]) {
			int child = v.first;
			int cost = v.second;
			if ((distance[child] > max(distance[parent], cost) && distance[child] > -1) || distance[child] == -1) {
				distance[child] = max(distance[parent], cost);
				pq.push({ distance[child], child });
			}
		}
	}
	return distance;
}

void task() {
	init();
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	int t; cin >> t;
	vector<int> distance = dijkstra(t);
	for (int i = 0; i < n; i++) {
		if (distance[i] == -1) {
			cout << "Impossible" << endl;
		}
		else cout << distance[i] << endl;
	}
}

int main() {
	//ctrl+alt+b
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T = 1; cin >> T;
	for (int __ = 1; __ <= T; __++) {
		cout << "Case " << __ << ":" << endl;
		task();
	}

	return 0;
}
