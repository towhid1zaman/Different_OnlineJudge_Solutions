
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
const int maxn = 50005;

ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a, ll b){
    return a/ gcd(a,b)*b;
}
int cs = 1;
void task(){
    ll a,b,l; cin >> a >> b >> l;
    ll lc = lcm(a,b);
    cout<<"Case "<<cs++<<": ";
    if(l%lc)cout <<"impossible"<<endl;
    else{
        ll c = l/lc;
        ll d = gcd(c,l);
        ll ans=1;
        while(d!=1){
            d = gcd(c,l);
            l/=d;
            ans*=d;
        }
        cout << ans << endl;
    }
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
