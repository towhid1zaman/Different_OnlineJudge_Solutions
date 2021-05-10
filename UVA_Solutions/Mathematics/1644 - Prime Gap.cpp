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
const int maxn = 1500000;
const int mod = 1000000007;

        
std::vector<int>prime;
bool isPrime[maxn];

void sieve(){
    int N = maxn, sq = sqrt(N);
    memset(isPrime, true, sizeof isPrime);
    for(int i = 4; i<=N; i+=2){
        isPrime[i] = 0;
    }
    for(int i = 3; i<=sq; i+=2){
        if(isPrime[i]){
            for(int j = i*i; j<=maxn; j+=i){
                isPrime [j] = 0;
            }
        }
    }
    isPrime[1] = 0;
    isPrime[0] = 0;
    prime.push_back(2);
    for(int i = 3; i<=maxn; i+=2){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
}

void task(){
    int n;
    while(cin >> n){
      if(!n)break;
      int gap = 0;
      int pos = lower_bound(all(prime), n) - prime.begin();
      gap = prime[pos] - prime[pos - 1];
      if(prime[pos] == n)gap = 0;
      cout << gap << endl;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
