
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
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
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

int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            ll n,m,k; cin >> n >> m >> k;
            vector<vector<ll>> a(n,vector<ll>(k));
            vll ans(n);
            rep(i,n){
                map<ll,ll>mp;
                rep(j,k){
                    cin >> a[i][j];
                    mp[a[i][j]]++;
                }
                ll x,y;
                x = 0;
                y = 1;
                for(auto p : mp){
                    if(p.ss>x){
                        x = p.ss;
                        y = p.ff;
                    }
                }
                ans[i]=y;
            }
            rep(i,n)cout<<ans[i]<<' ';
            cout<<endl;

        }


return 0;
}
