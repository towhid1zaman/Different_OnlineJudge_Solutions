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

int n;
bool isp(int n){
  if(n<2)return 0;
  if(n==2)return 1;
  for(int i = 2; i*i<=n; i++){
    if(n%i==0)return 0;
  }
  return 1;
}

int equ(int x){
  return (n - x);
}
void task(){
    cin >> n;
    int ans = 0, rem = 0;
    for(int i = 2; i<=n; i++){
      int x = n/2 + 1;
      if(isp(i)){
        if(i>=x){
          cout << i << endl;
          break;
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

    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
