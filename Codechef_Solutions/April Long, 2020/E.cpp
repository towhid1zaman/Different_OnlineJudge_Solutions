
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
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back
#define inf (1<<29)

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 1000100;

int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            ll n; cin >> n;
            vll a(n+1);
            rep1(i,1,n){
                cin >> a[i];
            }

            ll sum = 0;
            rep1(i,1,n){
                if(a[i]%2==0)continue;
                ll j = i, cnt = 0;
                while(j<=n and a[j]&1){
                    j++,cnt++;
                }
                i = j-1;
                sum+=(cnt*(cnt+1))/2;
            }
            ll prf[n+10];
            fill(prf);
            vll temp;
            rep1(i,1,n){
                if(a[i]&1)prf[i]=1;
                else temp.pb(i);
            }
            rep1(i,2,n){
                if(a[i]&1 and a[i-1]&1){
                    prf[i]+=prf[i-1];
                }
            }
            rep1(i,1,n){
                if(a[i]&1)continue;
                auto chek = upper_bound(all(temp),i) - temp.begin();
                //cout<<chek<<endl;
                if(chek==sz(temp))break;

                ll left =  prf[i-1]+1;
                ll right =  n-temp[chek]+1;
                sum+=(left*right);
            }
            temp.pb(n+1);

            rep1(i,1,n){
                if(a[i]%4==0){
                    auto chek = upper_bound(all(temp),i) - temp.begin();
                    ll left = prf[i-1]+1;
                    ll right = temp[chek] - i;
                    sum+=(left*right);
                }
            }
            cout<<sum<<endl;
        }

return 0;
}





