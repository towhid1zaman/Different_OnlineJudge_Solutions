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
const int maxn = 500005;
const int mod = 1000000007;


#define M 500006
std::vector<int>primes;
int marked[(M>>6) + 2];

#define on(x) (marked[x>>6] & ( 1<<((x>>1)&31 )))
#define mark(x) (marked[x>>6] |= ( 1<<( (x>>1)&31 )))

bool isPrime(int n){
  if(n==2 or n==4)return true;
  if(n%2==0 or n<2) return false;
  return !on(n);
}

void sieve(int n = M){
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

int pfsum(int n){
  int sum = 0;
  for(int i = 0; i<primes.size() and primes[i]*primes[i]<=n; i++){
    if(n%primes[i] == 0){
      while(n%primes[i] == 0){
        sum+=primes[i];
        n/=primes[i];
      }
    }
  }
  if(n>1)sum+=n;
  return sum;
}
int solof(int n){
    int cur, cnt = 1;
    while(!isPrime(n)){
      cur = pfsum(n);
      cnt++;
      n = cur;
    }
    return cnt;
}

void task(){
    int n, m; cin >> n >> m;
    if(n > m)swap(n, m);
    int ans = 0;
    for(int i = n; i<=m; i++){
      ans = max(solof(i), ans);
    }
    cout << ans << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        cout <<"Case #"<<__<<":"<<endl;
        task();
    }

return 0;
}
