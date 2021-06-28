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
const int maxn = 3001;
const int mod = 1000000007;

template <class T>
struct knapsack{
    /*
    knansack<ll>knap;
    knap.c = w;
    knap.add_item(weight, value);
    ans = knap.solve();
    */
    T c; 
    struct item{
        T p, w; 
    };
    std::vector<item> is;
    void add_item(T p, T w) {
        is.push_back({p, w});
    }
    T det(T a, T b, T c, T d) {
        return a * d - b * c;
    }
    T z;
    void go(T p, T w, int s, int t){
        if (w <= c){
          if (p >= z) z = p;
          for (; t < is.size(); ++t) {
            if (det(p - z - 1, w - c, is[t].p, is[t].w) < 0) return;
            go(p + is[t].p, w + is[t].w, s, t + 1);
        }
    }
    else {
        for (; s >= 0; --s) {
            if (det(p - z - 1, w - c, is[s].p, is[s].w) < 0) return;
            go(p - is[s].p, w - is[s].w, s - 1, t);
          }
        }
    }

    T solve(){
        sort(all(is), [](const item &a, const item &b) { 
            return a.p * b.w > a.w * b.p;
        });
        T p = 0, w = 0;
        z = 0;
        int b = 0; 
        for (; b < is.size() && w <= c; ++b) {
            p += is[b].p;
            w += is[b].w;
        }
        go(p, w, b-1, b);
        return z;
    }
};
void task(){
    int n,w; cin >> n >> w;
    knapsack<long long>knap;
    knap.c = w;
    for(int i = 0; i<n; i++){
        int a, b; cin >> a >> b;
        knap.add_item(b, a);
    }

    ll ans = knap.solve();
    cout << ans << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
