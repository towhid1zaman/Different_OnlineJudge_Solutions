
// </> : towhid1zaman


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


int cs = 1;
string maze[222];
int cost_jane[222][222], cost_fire[222][222];
int n, m;

struct graph{
	int x,y,c;
}parent, child;


//const int kx[8] = {-2, -2, -1, 1, -1, 1, 2, 2}, ky[8] = {1, -1, -2, -2, 2, 2, -1, 1}; //knight
//const int dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy8[8] = {0, 1, 0, -1, -1, 1, -1, 1}; //king
const int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};
// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
const int dx8[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
const int dy8[8] = { 0, 1, 0,-1,  1, 1, -1, -1};
// Represents all moves of a knight in a chessboard
const int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
const int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};
bool gridCheck(int x, int y) { 
    return x >= 0 && y >= 0 && x < n && y < m and maze[x][y] !='#'; 
}

void bfs_jane(int x, int y){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cost_jane[i][j] = inf;
		}
	}

	parent.x = x, parent.y = y, parent.c = 0;

	queue<graph>q;
	q.push(parent);

	cost_jane[x][y] = 0;

	while(!q.empty()){
		parent = q.front();
		q.pop();

		for(int i = 0; i<4; i++){
			child.x = parent.x + dx4[i];
			child.y = parent.y + dy4[i];

			if(gridCheck(child.x, child.y) and cost_jane[child.x][child.y]==inf){
				child.c = cost_jane[child.x][child.y] = cost_jane[parent.x][parent.y] + 1;
				q.push(child);
			}

		}
	}
}

void bfs_fire(){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cost_fire[i][j] = inf;
		}
	}

	queue< graph > q;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(maze[i][j] == 'F'){
				parent.x = i, parent.y = j, parent.c = 0;
				q.push(parent);
				cost_fire[i][j] = 0;
			}
		}
	}

	while(!q.empty()){
		parent = q.front();
		q.pop();

		for(int i = 0; i<4; i++){

			child.x = parent.x + dx4[i];
			child.y = parent.y + dy4[i];

			if(gridCheck(child.x, child.y) and cost_fire[child.x][child.y]==inf){
				child.c = cost_fire[child.x][child.y] =  cost_fire[parent.x][parent.y] + 1;
				q.push(child);
			}
		}
	}
}
void task(){
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> maze[i];
	}

	int f_cnt = 0;
	int jane_i, jane_j;
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(maze[i][j]=='J'){
				jane_i = i, jane_j = j;
			}
			if(maze[i][j] == 'F')f_cnt++;
		}
	}

	bfs_jane(jane_i, jane_j);
	bfs_fire();

	int ans = inf;

	for(int i = 0; i<m; i++){
		if(cost_fire[0][i] > cost_jane[0][i]){
			ans = min( ans, cost_jane[0][i]);
		}

		if(cost_fire[n-1][i] > cost_jane[n-1][i]){
			ans = min( ans, cost_jane[n-1][i]);
		}
	}

	for(int i = 0; i<n; i++){
		if(cost_fire[i][0] > cost_jane[i][0]){
			ans = min( ans, cost_jane[i][0]);
		}

		if(cost_fire[i][m-1] > cost_jane[i][m-1]){
			ans = min( ans, cost_jane[i][m-1]);
		}
	}

	if(ans == inf){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		cout << ans + 1 << endl;
	}
}

int main(){
        
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; cin >> T;
        while(T--){
        	cout << "Case "<<cs++<<": ";
            task();
        }
        
        
return 0;
}
