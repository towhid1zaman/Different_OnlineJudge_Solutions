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



const double pi = acos(-1.0);
const int maxn = 200005;
const int mod = 1000000007;

int charVal(char c){
  if(c<='9' and c>='0')return c - '0';
  else return c - 'A' + 10;
}
ll transform(string s, int n, int base){
    ll sum = 0;
    for(int i = 0; i<n ; i++){
      sum*=base;
      sum+=charVal(s[i]);
    }
    return sum;
}

void task(){
    string s, t;
    while(cin >> s >> t){
      int n = s.size(), m = t.size();
      
      int mxS = 1, mxT = 1;
      for(int i = 0; i<n; i++){
        mxS = max(mxS, charVal(s[i]));
      }
      for(int i = 0; i<m; i++){
        mxT = max(mxT, charVal(t[i]));
      }
      
      bool ok = 1;
      for(int i = mxS + 1; i<37 and ok; i++){
        ll curA = transform(s, n, i);
        for(int j = mxT + 1; j<37 and ok; j++){
          ll curB = transform(t, m, j);
          if(ok and curA == curB){
            cout << s<<" (base "<<i<<") = "<<t<<" (base "<<j<<")"<<endl;
            ok = 0;
          }
        }
      }
      if(ok){
        cout << s <<" is not equal to "<< t <<" in any base 2..36"<<endl;
      }
    }
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
