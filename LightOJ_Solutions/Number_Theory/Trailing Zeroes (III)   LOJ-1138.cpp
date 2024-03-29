
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
const int maxn = 1000;

ll zero(ll x){
    ll res = 0;
    while(x){
        res+=x/5;
        x/=5;
    }
    return res;
}
ll BS(ll x){
    ll l = 1, r = 500000000, ans = 0;
    while(l<=r){
        ll mid = (l+r)/2;
        if(zero(mid)==x){
            ans = mid;
            r = mid-1;
        }
        else if(zero(mid)>x){
            r = mid - 1;
        }
        else l = mid+1;
    }
    return ans;
}
int cs = 1;
void task(){


    ll x; cin >> x;
    ll ans = BS(x);
    if(ans==0)cout<<"Case "<<cs++<<": "<<"impossible"<<endl;
    else cout<<"Case "<<cs++<<": "<<ans<<endl;
}

int main(){
        //_
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


