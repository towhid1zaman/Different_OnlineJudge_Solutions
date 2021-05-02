#include <bits/stdc++.h>
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
const int maxn = 200005;
const int mod = 1000000007;



template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbug(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}


int charToint(char c){
  if(c<='9' and c>='0')return c - '0';
  else return c - 'A' + 10;
}

char intTochar(int n){
  if(n<=9)return n+'0';
  else return 'A' + (n-10);
}

ll convertToDecimal(string s, int base){
    reverse(all(s));
    int n = s.size();
    ll number = 0;
    for(int i = 0; i<n; i++){
      number+=(pow(2, i+1) - 1) * charToint(s[i]);
    }
    return number;
}

string Decimal_to_AnyBase(ll n,int base){
    string ans;
    while(n){
      ans.push_back(intTochar(n%base));
      n/=base;
    }
    if(ans.empty())ans.push_back('0');
    reverse(all(ans));
    return ans;
}

bool isValidBase(string s, int base){
  int n = s.size();
  int ok = 0;
  for(int i = 0; i<n; i++){
    if(charToint(s[i]) >= base)ok = 1;
  }
  return ok;
}

void task(){
    string s;
    while(cin >> s){
      if(s == "0")break;
      cout << convertToDecimal(s, 2) << endl;
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
