
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a,b) memset(a, b, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
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

bool sortOrnot(vll a, vll b,ll n){
    for(ll i=0;i<n;i++){
        if(a[i]!=b[i])
        return 0;
    }
    return 1;
}
int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            ll n,k; cin >> n >> k;
            vll a,b;
            rep(i,n){
                ll x; cin >> x;
                a.pb(x);
                b.pb(x);
            }
            bool chek = false;
            bool ans = false;
            sort(all(b));
            for(ll j = 0;; j++){
                for(ll i=0;i<n-k;i++){
                    if(a[i]>a[i+k]){
                        swap(a[i],a[i+k]);
                        chek = true;
                    }
                }
                if(chek){
                    if(sortOrnot(a,b,n)){
                        ans = true;
                        break;
                    }
                    else{
                        chek = false;
                        continue;
                    }
                }
                else{
                    ans = true;
                    break;
                }
            }
            if(sortOrnot(a,b,n)){
                cout<<"yes"<<endl;
            }
            else cout<<"no"<<endl;
        }


return 0;
}
