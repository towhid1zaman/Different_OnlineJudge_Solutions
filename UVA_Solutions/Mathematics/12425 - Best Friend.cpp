
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair< int, int > pii;
typedef vector<pii>vip;
typedef pair< pii, int > ppi;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 1000005;

//phi function
ll phi(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; p++)
        if (n % p == 0) {
            result = result / p * (p - 1);

            do {
                n /= p;
            } while (n % p == 0);
        }

    if (n > 1)
        result = result / n * (n - 1);

    return result;
}
vll fact,pre;
void Factor_and_PreCal(ll n){
	for(ll i = 1; i*i<=n; i++){
		if(n%i==0){
			fact.pb(i);
			if(i*i!=n)fact.pb(n/i);
		}
	}
	sort(all(fact));
	for(int i = 0; i<fact.size(); i++){
		pre.pb(phi(n/fact[i]));
		if(i)pre[i]+=pre[i-1];
	}
}
void task(){
 	ll n,q; cin >> n >> q;
 	fact.clear(),pre.clear();
 	Factor_and_PreCal(n);
 	while(q--){
 		ll x; cin >> x;
 		if(x>=n){
 			cout << n << endl;
 		}
 		else if(x<1){
 			cout << 0 << endl;
 		}
 		else{
 			ll pos = upper_bound(fact.begin(),fact.end(),x)-fact.begin();
 			pos--;
 			cout << pre[pos] << endl;	
 		}
 	}
}
int cs = 1;
int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; cin >> T;
        while(T--){
        	cout <<"Case "<<cs++<<endl;
            task();
        }
        
return 0;
}


