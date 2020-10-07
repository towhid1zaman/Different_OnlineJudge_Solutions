
// </> : towhid1zaman

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("avx,avx2,fma") 
#pragma comment (linker,"/STACK:16777216")
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

vi mods = {1000000007, 1000000009, 998244353};
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 2005;

/*
 *
 */

int dist[maxn][maxn], visit[maxn][maxn];
int n,m,tx,ty;
const int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
const int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};
bool gridCheck(int x, int y) { 
    return x >= 1 && y >= 1 && x <= n && y <= m; 
}

void Reset(){
	rep(i, 50)rep(j,50){
		dist[i][j]  = 0, visit[i][j] = 0;
	}
}

void bfs(int ii, int jj){
	queue<pii>q;
	q.push({ii, jj});
	dist[ii][jj] = 0;
	visit[ii][jj] = 1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x==tx and y==ty){
			cout << dist[x][y] << endl;
			return;
		}
		for(int i = 0; i<8; i++){
			int xx = x + dxKnightMove[i];
			int yy = y + dyKnightMove[i];
			if(gridCheck(xx,yy) and !visit[xx][yy]){
				visit[xx][yy] = 1;
				dist[xx][yy] = dist[x][y] + 1;
				q.push({xx,yy});
			}
		}
	}
}
void task(){
	Reset();
	string x,y; cin >> x >> y;
	int x1 = x[0]-'a' + 1, y1 = x[1]-'0';
	int x2 = y[0]-'a' + 1, y2 = y[1]-'0';
	n = 8, m = 8;
	tx = x2, ty = y2;
	//cout << x1 << y1 << endl<<x2 << y2<<endl;
	bfs(x1, y1);

}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1,tc = 1; cin >> T;
        while(T--){
            //cout <<"Case "<<tc++<<": ";
            task();
        }
        
        
return 0;
}


