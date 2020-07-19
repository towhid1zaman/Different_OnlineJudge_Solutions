
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const int INF = 1e9 + 10;
const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            int n; cin >> n;
            vi a(n);
            rep(i,n) cin >> a[i];
            int chek,res;
            ll ans =1;
            rep1(i,1,n-1){
                chek = a[i-1];
                res =  a[i];
                while(chek or res){
                    int x = chek&1;
                    int y = res&1;
                    if(x==1 and y==1){
                        ans*=2;
                        ans%=mod;
                    }
                    else if(x==1 and y==0){
                        ans = 0;
                        break;
                    }
                    chek = (chek>>1);
                    res = (res>>1);
                }
            }
            ans%=mod;
            cout<<ans<<endl;
        }


return 0;
}






