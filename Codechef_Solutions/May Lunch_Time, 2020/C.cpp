
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair< int, int > pii;
typedef pair< pii, int > ppi;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(ll i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) (v).erase(unique(all(v)),(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;
const int maxn = 2000100;



int main(){
        _
        int T; cin >> T;
        while(T--){
            bool f = 1;
            string a,b;
            ll n; cin >> n;
            cin >> a >> b;
            int frq[256];
            fill(frq,0);
            map<char, vll >mp;
            rep(i,n){
                frq[a[i]] = i+1;
            }
            rep(i,n){
                mp[b[i]].pb(i);
            }
            ll chek = 0, cnt = 0;
            vector<vector<ll>>ans;

            for(char c = 'z'; c>='a'; c--){
                vll st;
                vll ar = mp[c];
                rep(i,sz(ar)){
                    if(a[ar[i]] < b[ar[i]] or frq[c]==0){
                        cout<<-1<<endl;
                        f = 0;
                        break;
                    }
                    if(a[ar[i]] == b[ar[i]])continue;
                    st.pb(ar[i]);
                }
                if(f and sz(st)!=0){
                    st.pb(frq[c]-1);
                    ans.pb(st);
                }
                if(!f)break;
            }
            if(f)cout<<sz(ans)<<endl;
            if(f){
                rep(i,sz(ans)){
                    cout<<ans[i].size()<<' ';
                    for(auto it=ans[i].begin();it!=ans[i].end();it++){
                        cout<<*it<<" ";
                    }
                    cout<<endl;
                }
            }
        }

return 0;
}


