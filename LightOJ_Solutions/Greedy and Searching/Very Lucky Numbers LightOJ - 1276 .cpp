

// </> : towhid1zaman

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("avx,avx2,fma") 
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define deb(x) cout<<#x <<"="<<x<<endl;
#define present(v,x) ((v).find(x)!=(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define sp(k) cout<<setprecision(k)<<fixed;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()

#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)

#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define yn(k) if(k)puts("YES");else puts("NO");

vi mods = {1000000007, 1000000009, 998244353};
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;
const int mod = mods[0];

/*
 *
 */
vll lucky, vlucky;

void GenerateLucky(ll n){
    if(n>1000000000000ll)return;
    if(n!=0)lucky.pb(n);
    GenerateLucky(n*10+4);
    GenerateLucky(n*10+7);
}

void GenerateVLucky(ll sum, int index){
    if(sum>1)vlucky.pb(sum);
    for(int i = index; i<lucky.size(); i++){
        if(sum > 1000000000000ll / lucky[i])return;
        GenerateVLucky(sum*lucky[i], i);
    }
}
void task(){
        ll x, y; cin >> x >> y;
        ll ans = upper_bound(all(vlucky), y) - lower_bound(all(vlucky), x);
        cout << ans << endl;
}

int main(){
        
#ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        
        GenerateLucky(0ll);
        sort(all(lucky));

        GenerateVLucky(1ll,0);
        unq(vlucky);

        int T = 1; cin >> T;
        for(int __ = 1; __ <= T; __++){
            cout <<"Case "<<__<<": ";
            task();
        }


/*array size ?
 *n==1 ?
 *different approach ?
*/        
return 0;
}
