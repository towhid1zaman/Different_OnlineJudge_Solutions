
// </> : towhid1zaman

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define deb(x) cout<<#x <<"="<<x<<endl;
#define present(v,x) ((v).find(x)!=(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define sp(k) cout<<setprecision(k)<<fixed;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()


#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)

#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define yn(k) if(k)puts("YES");else puts("NO");

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;

/*
 *
 */

int n;
std::vector<vi>adj;
bool visit[111];

void bfs(int s){
	fill(visit, 0);

	queue<int>q;
	q.push(s);

	while(!q.empty()){
		int p = q.front();
		q.pop();

		for(auto v: adj[p]){
			if(!visit[v]){
				visit[v] = 1;
				q.push(v);
			}
		}
	}

	vi ans;
	for(int i = 0; i<n; i++){
		if(!visit[i])ans.pb(i+1);
	}
	cout << ans.size();
	for(auto v:ans)cout <<' '<<v;
	cout << endl;
	ans.clear();
}

void task(){
	while(true){
		cin >> n;
		if(!n)break;

		adj.clear();
		adj.resize(n);

		while(true){
			int a; cin >> a;
			if(!a)break;

			while(true){
				int b; cin >> b;
				if(!b)break;

				adj[a-1].push_back(b-1);
			}
		}

		int Q; cin >> Q;
		for(int i = 0; i<Q; i++){
			int a; cin >> a;
			bfs(a-1);
		}
	}
}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; //cin >> T;
        while(T--){
            task();
        }
        
        
return 0;
}


