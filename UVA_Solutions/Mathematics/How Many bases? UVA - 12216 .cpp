
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
const int mod = 100000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;
ll n,m,k,ans1,ans2;
inline ll MOD(ll x)
{
    ll y = x % mod;
    return (y >= 0) ? y: y+mod; // if -ve, simply add M
}
int cs = 1;
void task(){
    while(1){
        cin >> n >> m >> k;
        if(n==0 && m==0 && k==0)break;
        ans1 = 1;
        ans2 = 1;
        for(ll i = 2;i*i<=n; i++){
            if(n%i==0){
                ll cnt = 0;
                while(n%i==0){
                    n/=i;
                    cnt++;
                }
                cnt*=m;
                ans1=ans1*(cnt/k+1)%mod;
                ans2=ans2*(cnt/(k+1)+1)%mod;
            }
        }
        if(n!=1){
            ans1=ans1*(m/k+1)%mod;
            ans2=ans2*(m/(k+1)+1)%mod;
        }
        ll ans = MOD(ans1-ans2);
        cout <<"Case "<< cs++ <<": "<< ans << endl;
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
