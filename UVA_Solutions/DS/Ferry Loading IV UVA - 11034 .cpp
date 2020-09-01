
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

/*given a ferry length and said that how many times this ferry need to cross the river.
 * every time given the side that currently ferry now, and some car and their length.
 * i used two queue of left and right, and every time i check wheather the ferry now
 * left or right side, and i check car length over the ferry length or not
 */

void task(){
	ll ferrylength,m; cin >> ferrylength >> m;
	ferrylength*=100;
	queue<ll>left, right;
	rep(i,m){
		ll lcar;
		string side;
		cin >> lcar >> side;
		if(side=="left")left.push(lcar);
		else right.push(lcar);
	}
	int rightBank = 0;
	int crossing = 0;
	while(!left.empty() or !right.empty()){
		ll load = 0;
		if(rightBank){
			while(!right.empty() and load+right.front()<=ferrylength){
				load+=right.front();
				right.pop();
			}
		}
		else{
			while(!left.empty() and load+left.front() <= ferrylength){
				load+=left.front();
				left.pop();
			}
		}
		crossing++;
		rightBank ^= 1;
	}
	cout << crossing << endl;
}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; cin >> T;
        while(T--){
            task();
        }
        
        
return 0;
}


