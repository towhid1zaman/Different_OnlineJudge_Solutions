
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

ll bxp(ll x,ll n){
    ll res = 1;
    while(n){
        if(n%2){
            res = (res*x)%mod;
        }
        n/=2;
        x = (x*x)%mod;
    }
    return res;
}
int main(){
        //_ios;

        int T; cin >> T;
        int cs = 1;
        while(T--){
            ll n,m; cin >> n >> m;
            vector<pair<ll,ll>>pf;
            for(ll i = 2; i*i<=n; i++){
                if(n%i)continue;
                ll cnt = 0;
                while(n%i==0){
                    n/=i;
                    cnt++;
                }
                pf.pb({i,cnt*m});
            }
            if(n>1)pf.pb({n,m});

            ll ans = 1;
            for(auto pr : pf){
                ll p =  pr.ff;
                ll e = pr.ss;
                ll cur = ((bxp(p,e+1)+mod-1)*bxp(p-1,mod-2))%mod;
                ans = (ans*cur)%mod;
            }
            cout<<"Case "<<cs++<<": "<<ans<<endl;
        }


return 0;
}
