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

ll stolli(string s){
  ll ans = 0;
  for(int i = 0; i<s.size(); i++){
    ans = (ans*10) + (s[i]-48);
  }
  return ans;
}
void task(){
    string s;
    while(cin >> s){
      string a = s;
      sort(all(a));
      string b = a;
      reverse(all(b));
      for(int i = 0; i<a.size(); i++){
        if(a[i]!='0'){
          swap(a[0], a[i]);
          break;
        }
      }
      ll A = stolli(a), B = stolli(b);
      cout << B<<" - "<<A<<" = "<<B - A<<" = "<<9<<" * "<<(B-A)/9<<endl;
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
