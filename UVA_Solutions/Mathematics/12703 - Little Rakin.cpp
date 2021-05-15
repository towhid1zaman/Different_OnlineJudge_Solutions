/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
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


const double pi = acos(-1.0);
const int maxn = 200005;
const int mod = 1000000007;

std::vector< pair<ll, ll> > v;
void solve(ll n){
  v.clear();
  for(ll i = 2; i*i<=n and n > 1; i++){
    if(n%i!=0)continue;
    ll cnt = 0;
    while(n%i == 0){
      n/=i;
      cnt++;
    }
    v.emplace_back(i, cnt);
  }
  if(n > 1)v.emplace_back(n, 1);
}
ll F[42];
std::map<ll, ll> mark;
void task(){
    ll a, b, n; cin >> n >> a >> b;
    mark.clear();
    solve(a);
    for(auto x:v){
      mark[x.first] += (x.second * F[n-1]);
    }

    solve(b);
    for(auto x:v){
      mark[x.first] += (x.second * F[n]);      
    }
    //dbug(mark);
    for(auto x:mark){
      cout << x.first <<' '<<x.second<<endl;
    }
    cout << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    F[0] = 0, F[1] = 1;
    for(int i = 2; i<42; i++){
      F[i] = F[i- 1] + F[i-2];
    }

    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
