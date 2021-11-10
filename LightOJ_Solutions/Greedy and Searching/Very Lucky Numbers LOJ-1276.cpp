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
#define unq(v) sort(all(v)),v.erase(unique(all(v)),v.end());
const double pi = acos(-1.0);
const int maxn = 2000006;
const int mod = 1000000007;


namespace debugging{
    template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
    template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
    template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
    template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
    template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
    #define dbug(args...) do {cerr << #args << " : "; Hooo(args); } while(0)
    void Hooo(){cerr << endl;}
    template<typename T>void Hooo(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
    template<typename T,typename...hello>void Hooo(T arg,const hello&...rest){cerr<<arg<<' ';Hooo(rest...);}
}using namespace debugging;

vector<ll>lucky;
void GenerateLucky(ll n){
    if(n>1e12)return;
    if(n!=0)lucky.push_back(n);
    GenerateLucky(n*10+4);
    GenerateLucky(n*10+7);
}
void very_lucky(int start, int sz, ll n){
    if(n!=1 and n !=0)lucky.push_back(n);
    for(int i = start; i < sz;i++){
        if(n*lucky[i] <= 1e12 and n*lucky[i] > 0)very_lucky(i, sz, n*lucky[i]);
        else break;
    }
}
void task(){
    ll a, b; cin >> a >> b;
    int l = lower_bound(lucky.begin(), lucky.end(), a) - lucky.begin();
    int u = upper_bound(lucky.begin(), lucky.end(), b) - lucky.begin();
    cout << u - l << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //lucky(1ll);
    GenerateLucky(0ll);
    sort(all(lucky));
    very_lucky(0ll,lucky.size(),1ll);
    unq(lucky);
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        cout <<"Case "<<__<<": ";
        task();
    }

return 0;
}

