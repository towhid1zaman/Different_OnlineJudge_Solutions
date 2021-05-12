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

        
#define M 10002
std::vector<int>primes;
int marked[(M>>6) + 2];

#define on(x) (marked[x>>6] & ( 1<<((x>>1)&31 )))
#define mark(x) (marked[x>>6] |= ( 1<<( (x>>1)&31 )))

bool isPrime(int n){
  if(n%2==0 or n<2) return false;
  return !on(n);
}

void sieve(int n){
  for(int i = 3; i*i < n; i+=2){
    if(!on(i)){
      for(int j = i*i; j<=n; j += i+i){
        mark(j);
      }
    }
  }

  primes.push_back(2);
  for(int i = 3; i<=n; i+=2){
    if(isPrime(i)){
      primes.push_back(i);
    }
  }

}



void task(){
    int n;
    while(cin >> n){
        if(!n)break;
        int ans = 0, sum = 0;
        for(int i = 0; i<primes.size(); i++){
            sum = 0;
            for(int j = i; j<primes.size(); j++){
                sum+=primes[j];
                if(sum == n){
                    ans++;
                    sum = 0;
                    break;
                }
            } 
        }
        cout <<ans << endl;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve(M);
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
