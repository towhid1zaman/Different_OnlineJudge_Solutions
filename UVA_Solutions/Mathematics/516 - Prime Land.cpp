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
const int maxn = 200005;
const int mod = 1000000007;


void solve(int n){
  std::vector< pair<int, int> > v;
  for(int i = 2; i*i<=n and n > 1; i++){
    if(n%i!=0)continue;
    int cnt = 0;
    while(n%i == 0){
      n/=i;
      cnt++;
    }
    v.emplace_back(i, cnt);
  }
  if(n > 1)v.emplace_back(n, 1);
  reverse(all(v));
  for(int i = 0; i<v.size(); i++){
    cout << v[i].first<<' '<<v[i].second;
    if(i<v.size() - 1)cout << ' ';
  }
  cout << endl;
}
void task(){
    string s;
    while(getline(cin, s)){
      if(s.size() and s[0]=='0')break;
      stringstream ss(s);
      ss.clear();
      int a,b;
      int tt = 0;
      int mult = 1;
      while(ss>>a>>b){
        while(b--)mult*=a;
      }
      solve(mult - 1);
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
