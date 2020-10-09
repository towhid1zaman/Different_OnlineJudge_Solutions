
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
const int maxn = 1010;

/*
 *
 */

string s[maxn];
bool vis[maxn][maxn];
int n, m;

const int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

bool gridCheck(int x, int y) { 
    return x >= 0 && y >= 0 && x < n && y < m; 
}

void dfs(int ii, int jj){
	s[ii][jj] = '#';
	for(int i = 0; i<4; i++){
		int x = ii+dx4[i];
		int y = jj+dy4[i];
		if(gridCheck(x,y) and s[x][y]!='#'){
			dfs(x,y);
		}
	}
}

void task(){
	fill(vis,0);
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >>s[i];
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(s[i][j]!='#'){
				dfs(i,j);
				ans++;
			}
		}
	}

	cout << ans<< endl;
}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1,tc = 1; //cin >> T;
        while(T--){
            //cout <<"Case "<<tc++<<": ";
            task();
        }
        
        
return 0;
}


