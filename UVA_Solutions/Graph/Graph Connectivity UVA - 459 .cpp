
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
const int maxn = 101;

/*
 *
 */
vector<int>adj[maxn];
int vis[maxn];
queue<int>q;
void bfs(int node){
	vis[node] = 1;
	q.push(node);
	
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(auto v:adj[p]){
			if(!vis[v]){
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}

void task(){
	char ch[maxn], s[maxn];
	int ans = 0;
	gets(ch);
	int node = ch[0]-'A';
	for(int i = 0; i<=node; i++)adj[i].clear();
	while(gets(s)&&s[0]){
		int u = s[0]-'A';
		int v = s[1]-'A';
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fill(vis, 0);
	for(int i = 0; i<=node; i++){
		if(!vis[i]){
			ans++;
			bfs(i);
		}
	}
	cout << ans << endl;
}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif
        int T = 1; 
        scanf("%d\n", &T);
        while(T--){
            task();
            if(T) cout << endl;
        }
        
        
return 0;
}


