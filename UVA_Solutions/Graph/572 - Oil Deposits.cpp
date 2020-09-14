
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

//const int kx[8] = {-2, -2, -1, 1, -1, 1, 2, 2}, ky[8] = {1, -1, -2, -2, 2, 2, -1, 1}; //knight
//const int dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy8[8] = {0, 1, 0, -1, -1, 1, -1, 1}; //king
const int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};
// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
const int dx8[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
const int dy8[8] = { 0, 1, 0,-1,  1, 1, -1, -1};
// Represents all moves of a knight in a chessboard
const int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
const int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

bool gridCheck(int x, int y,int n, int m) { 
    return x >= 0 && y >= 0 && x < n && y < m; 
}
char mat[111][111];
int m,n;
void dfs(int x, int y){
	mat[x][y] = '*';
	for(int i = 0; i<8; i++){
		int p = x+dx8[i];
		int q = y+dy8[i];
		if(gridCheck(p,q,m,n) and mat[p][q]!='*'){
			if(mat[p][q]=='@')dfs(p,q);
		}
	}
}

void task(){
	while(true){
		cin >> m >> n;
		if(!m)break; 
		
		for(int i = 0; i<m; i++){
			for(int j = 0; j<n; j++){
				cin >> mat[i][j];
			}
		}
		int cnt = 0;
		for(int i = 0; i<m; i++){
			for(int j = 0; j<n; j++){
				if(mat[i][j]!='*'){
					cnt++;
					dfs(i,j);
				}
			}
		}
		cout<< cnt << endl;
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


