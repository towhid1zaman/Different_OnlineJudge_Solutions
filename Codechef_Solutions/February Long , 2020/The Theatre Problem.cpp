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
#define ff first
#define ss second
#define pb push_back
#define sz(x) (int)x.size()

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 10;
const ll N = 1e18;

int main(){
        _ios;

        int T;
        cin>>T;
        ll totearn = 0;
        while(T--){
            int n;
            cin>>n;
            int cnt[maxn][maxn];
            fill(cnt);
            ll ans = -N;
            rep(i,n){
                char m;
                int p;
                cin>>m>>p;
                p/=3;
                cnt[m-'A'][p-1]++;
            }
            string a="0123",b="ABCD";
            do{
                do{
                    ll res = 0;
                    rep(i,4){
                        if(cnt[b[i]-'A'][a[i]-'0']>0)res = res + (cnt[b[i]-'A'][a[i]-'0'])*(i+1)*25;
                        else res-=100;
                    }
                    ans = max(ans,res);
                }while(next_permutation(all(b)));
            }while(next_permutation(all(a)));
            totearn+=ans;
            cout<<ans<<endl;
        }
        cout<<totearn<<endl;




return 0;
}





