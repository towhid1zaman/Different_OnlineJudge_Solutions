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

bool ispal(string s){
  string t = s;
  reverse(all(t));
  return s==t;
}

int check(string s, int b){
  int steps = 0;
  while(true){
    if(ispal(s)){
      return steps;
    }
    steps++;
    int l = 0, r = s.size() - 1;
    while(l <= r){
      s[l] = s[r] = (int)s[r] - (int)'0' + s[l];
      l++, r--;
    }

    l = s.size() - 1;
    for(int i = 0; i<l; i++){
      if(s[i]-'0' >= b)s[i]-=b, s[i+1]++;
    }
    if(s[l] - '0' >= b)s[l]-=b, s.push_back('1');
  }
}
void task(){
    string s;
    while(cin >> s){
      int b = 0;
      for(int i = 0; i<s.size(); i++){
        if(isdigit(s[i]))b = max(b, s[i]-'0');
        else b = max(b, s[i] - 'A' + 10), s[i] = s[i] - 'A' + '0' + 10;
      }
      for(int i = 15; i>1; i--){
        if(b>=i){
          if(i==2)cout << '?'<<endl;
          else cout << '?'<<' ';
        }
        else{
          if(i==2)cout << check(s, i)<<endl;
          else cout << check(s, i)<<' ';
        }
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
