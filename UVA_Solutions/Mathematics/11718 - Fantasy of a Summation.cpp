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

template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbug(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}


const int maxn = 200005;
const int mod = 1000000007;
struct Combinatorics{
    ll fact[maxn],inv[maxn];
 
    ll BigMod(ll b,ll p,ll m){
        ll ret = 1;
        while(p > 0){
            if(p&1)ret = (ret * b) % m;
            p = p >> 1;
            b = (b * b) % m;
        }
        return ret;
    }
 
    void Build(ll n){
        fact[0] = 1;
        for(int i = 1;i <= n+2;i++){
            fact[i] = (fact[i - 1] * i) % mod;
        }
        for(int i = 0;i <= n+2;i++){
            inv[i] = BigMod(fact[i],mod-2,mod);
        }
    }
 
    ll Choose(ll n,ll r){
        if(n < r)return 0;
        ll u = fact[n];
        ll v = (inv[r] * inv[n - r]) % mod;
        return (u * v) % mod;
    }

    ll Factorial(ll n){
        return fact[n];
    }

}combi;

void task(){
    ll n, k, Mod; cin >> n >> k >> Mod;

    ll sum = 0;
    rep(i, n){
        ll a; cin >> a;
        sum+=a;
    }
    sum%=Mod;
    ll pw = combi.BigMod(n,k-1,Mod);
    cout << ((sum*pw*k)%Mod) << endl;
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
