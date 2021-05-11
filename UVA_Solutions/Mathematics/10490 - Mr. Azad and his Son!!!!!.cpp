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

bool isp(int n){
  if(n<2)return 0;
  if(n==2)return 1;
  for(int i = 2; i*i<=n; i++){
    if(n%i==0)return 0;
  }
  return 1;
}

std::map<int, ll> pn;
void pre(){
  pn[2] = 6;
  pn[3] = 28;
  pn[5] = 496;
  pn[7] = 8128;
  pn[13] = 33550336;
  pn[17] = 8589869056;
  pn[19] = 137438691328ll;
  pn[31] = 2305843008139952128ll;
}
void task(){
    int n;
    while(cin >> n){
      if(!n)break;
      if(pn[n])cout <<"Perfect: "<< pn[n]<<"!"<<endl;
      else if(!pn[n] and isp(n)){
        cout << "Given number is prime. But, NO perfect number is available."<<endl;
      }
      else if(!pn[n] and !isp(n)){
        cout <<"Given number is NOT prime! NO perfect number is available."<<endl;
      }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    pre();
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
