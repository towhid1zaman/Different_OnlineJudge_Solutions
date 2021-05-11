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
    

bool isPrime(int n){
        if(n==2){
            return true;
        }
        if(n<2 || n%2==0){
            return false;
        }
        for(int i = 3; i*i<=n;i+=2){
            if(n%i==0){
                return false;
            }
        }
        return true;
}


void task(){
    string n; 
    while(cin >> n){
      if(n=="0")break;
      int ans = 0;
      for(int len = 1; len<6;len++){  
        for(int i = 0; i<=n.size()-len; i++){
          int j = i+len - 1;
          string s="";
          for(int k = i; k<=j; k++){
            s+=n[k];
          }         
            int N = stoi(s);
            if(isPrime(N))ans = max(ans, N);
        }
      }
      cout << ans << endl;
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
