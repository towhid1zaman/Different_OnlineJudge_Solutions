
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
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
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

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 105;

int mat[maxn][maxn];

void task(){
	int n;
	while(true){
		cin >> n;
		if(!n)break;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				cin >> mat[i][j];
			}
		}
		std::vector<pii> ans;
		int cnt = 0;
		for(int r = 0; r<n; r++){
			int row = 0, col = 0;
			for(int c = 0; c<n; c++){
				row+=mat[r][c];
			}
			for(int C = 0;C<n; C++){
				col = 0;
				for(int R = 0; R<n; R++){
					col+=mat[R][C];
				}
				if(row%2==1 and col%2==1){
					ans.eb(r+1, C+1);
				}
				if( !(col%2==0 and row%2==0) ){
					cnt++;
				}
			}
		}

		unq(ans);
		if(ans.size()==0 and cnt==0){
			cout << "OK" << endl;
		}
		else if(ans.size()==1){
			cout <<"Change bit ("<< ans[0].first<<','<<ans[0].second<<')'<<endl;
		}
		else cout <<"Corrupt"<<endl;
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
