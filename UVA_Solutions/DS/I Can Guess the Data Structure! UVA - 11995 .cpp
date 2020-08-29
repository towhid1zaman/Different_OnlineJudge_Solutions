
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
#define eb emplace_back
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

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;


void task(){
 	int n,c,x;
 	while( cin >> n ){
 	bool qq,ss,pqq;
	qq=ss=pqq=true;
	queue<int>q;
	stack<int>s;
	priority_queue<int> pq; // greater value first
 	while(n--){
 		cin >> c >> x;
 		if(c==1){
 			if(qq)q.push(x);
 			if(ss)s.push(x);
 			if(pqq)pq.push(x);
 		}
 		else{
 			if(qq){
 				if(q.empty() or q.front() != x)qq = false;
 				if(qq)q.pop();
 			}
 			if(ss){
 				if(s.empty() or s.top() != x)ss = false;
 				if(ss)s.pop();
 			}
 			if(pqq){
 				if(pq.empty() or pq.top() != x) pqq = false;
 				if(pqq)pq.pop();
 			}
 		  }
 	    }
 	    if(!qq && !ss && !pqq) cout << "impossible" << endl;
		else if(qq && !ss && !pqq) cout << "queue" << endl;
		else if(!qq && ss && !pqq) cout << "stack" << endl;
		else if(!qq && !ss && pqq) cout << "priority queue" << endl;
		else cout << "not sure" << endl;
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
