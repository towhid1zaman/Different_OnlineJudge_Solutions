
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

/*
 *
 */

int Left = 0, Right = 1;
void task(){
	int n,t,m; cin >> n >> t  >> m;
	//two queue store the car
	std::vector<queue<pii>> cars(2);
	std::vector<int> Uptime(m);
	rep(i, m){
		int arrivetime; string side;
		cin >> arrivetime >> side;
		if(side == "left")cars[Left].push({i,arrivetime});
		else cars[Right].push({i,arrivetime});
	}
	int time = 0;
	int bank = Left; // initially left bank;
	while(!(cars[Left].empty() and cars[Right].empty())){
		int earliestCar = inf;
		if(!cars[Left].empty()){
			earliestCar = cars[Left].front().second;
		}
		if(!cars[Right].empty()){
			earliestCar = min(earliestCar, cars[Right].front().second);
		}

		time = max(time, earliestCar);
		int car = 0;
		while(!cars[bank].empty() and car < n and cars[bank].front().second <= time){
			Uptime[ cars[ bank ].front().first ] = time+t;
			cars[ bank ].pop();
			car++;
		}
		time+=t;
		bank ^= 1;
	}
	rep(i, m){
		cout << Uptime[i]<<endl;
	}
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
            if(T)cout << endl;
        }
        
        
return 0;
}


