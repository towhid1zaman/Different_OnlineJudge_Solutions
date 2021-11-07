/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
#define endl "\n"
#define pb push_back
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define all(v) (v).begin(),(v).end()

const double pi = acos(-1.0);
const int maxn = 2000006;
const int mod = 1000000007;

vector<ll>subset(vector<ll>v){
    int n = v.size();
    vector<ll>sum;
    for(int i=0;i<(1<<n);i++){
        ll s = 0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))s += v[j];
        }
        sum.push_back(s);
    }
    return sum;
}
void task(){
    int n, w; cin >> n >> w;
    vector<ll>v1,v2,subset_v1, subset_v2;
    for(int i = 0; i<n; i++){
        ll a; cin >> a;
        if(i%2==0)v1.push_back(a);
        else v2.push_back(a);
    }
    subset_v1 = subset(v1);
    subset_v2 = subset(v2);
    sort(all(subset_v2));
    int ans = 0;
    for(ll a:subset_v1){
        ll need = w - a;
        int pos = upper_bound(subset_v2.begin(), subset_v2.end(), need) - subset_v2.begin();
        ans+=pos;
    }
    cout << ans << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        cout <<"Case "<<__<<": ";
        task();
    }

return 0;
}

