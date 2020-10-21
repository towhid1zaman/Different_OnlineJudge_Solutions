

// </> : towhid1zaman

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("avx,avx2,fma") 
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define deb(x) cout<<#x <<"="<<x<<endl;
#define present(v,x) ((v).find(x)!=(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define sp(k) cout<<setprecision(k)<<fixed;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()

#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)

#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define yn(k) if(k)puts("YES");else puts("NO");

vi mods = {1000000007, 1000000009, 998244353};
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;

/*not 10^5 its 10^5 digits
 *
 */

void solve(string s){
  int n = s.size();
  int mid = (n+1)/2;
  int pos = mid;

  for(int i = mid; i<n; i++){
    if(s[i] > s[n-i-1]){
      break;
    }
    pos = i;
  }
  for(int i = pos; i>=0; i--){
    if(s[i] != '9' and i<mid){
      s[i]++;
      for(int j = i+1; j<mid; j++){
        s[j] = '0';
      }
      break;
    }
    else if(s[i] !='9' and s[i]<s[n-i-1]){
      for(int j = i; j<n; j++){
        s[j] = s[n-j-1];
      }
      break;
    }
  }

  for(int i = mid; i<n; i++){
    s[i] = s[n-i-1];
  }

  cout << s << endl;

}
void allDigitNine(string s){
        string ans = "1";
        for(int i = 0; i<s.size()-1; i++){
          ans+="0";
        }
        ans+="1";
        cout << ans.c_str() << endl;
}

int task(){
        string s; cin >> s;
        bool nine = true;
        for(int i = 0; i<s.size(); i++){
          if(s[i] != '9'){
            nine = false;
          }
        }

        if(nine){
          allDigitNine(s);
        }
        else{
            solve(s);
        }

}

int main(){
        
#ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        int T = 1; cin >> T;
        for(int __ = 1; __ <= T; __++){

            cout <<"Case "<<__<<": ";
            task();
        }


/*array size ?
 *n==1 ?
 *different approach ?
*/        
return 0;
}





