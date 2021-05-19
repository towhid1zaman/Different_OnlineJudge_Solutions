
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
const int mod = 10000019; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;
bool checkprime[maxn + 5];
vll prime;
void sieve() {///false means prime
    prime.push_back(2);
    checkprime[0]=true;
    checkprime[1]=true;
    for (ll i = 3; i <= maxn; i += 2) {
        if (!checkprime[i]) {
            prime.push_back(i);
            for (ll j = i * i; j <= maxn; j += (i + i))
                checkprime[j] = true;
        }
    }
}
ll modexpo(ll x, ll n, ll m)
{
    ll res = 1;
    while(n){
        if(n & 1LL) res = (res*x) % m;
        x = (x*x) % m;
        n >>= 1;
    }
    return res;
}
int cs = 1;
void task(){
    ll n,r; cin >> n >> r;
    ll ans = 1;
    for(auto p:prime){
        if(p>n)break;
        ll cnt = 0;
        ll x = n;
        while(x){
            x/=p;
            cnt+=x;
        }
        if(cnt>=r){
            ans = ans * modexpo(p,cnt/r,mod)%mod;
        }
        if(cnt<r)break;
    }
    if(ans==1)cout <<"Case "<<cs++<<": -1"<<endl;
    else cout <<"Case "<<cs++<<": "<<ans<<endl;
}

int main(){
        //_
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif
        sieve();
        int T = 1; cin >> T;
        while(T--){
            task();
        }
        
return 0;
}


