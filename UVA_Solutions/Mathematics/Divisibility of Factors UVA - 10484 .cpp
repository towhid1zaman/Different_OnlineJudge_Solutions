
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
const int maxn = 200005;

void task(){
    ll n,d;
    while(true){
        ll cnt[111]{};
        cin >> n >> d;
        if(n==0 and d==0)break;
        
        for(ll i = 2; i<=n; i++){
            ll N = i;
            for(ll j = 2; j<=N; j++){
                while(N%j==0){
                    N/=j;
                    cnt[j]++;
                }
            }
        }
        ll zero = 0;
        for(ll i = 2; i<n and !zero; i++){
            while(d%i==0){
                if(!cnt[i]){
                    zero = 1;
                    break;
                }
                cnt[i]--;
                d/=i;
            }
        }
        //if N! isn't divisible by d then ans will be 0
        if(d!=1 and (d>100 or cnt[d]==0)) zero = 1;
        else if(d!=1)cnt[d]--;
        if(zero){
            cout<<0<<endl;
            continue;
        }
        ll ans = 1;
        for(ll i = 0; i<=n;i++){

            ans*=cnt[i]+1;
        }
        cout << ans << endl;
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
