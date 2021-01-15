#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma") 
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 1e6;
const int mod = 1000000007;
 
 
ll divi[maxn];
//quick sieve
bool checkprime[maxn + 5];
std::vector<ll>prime;
void sieve() {///false means prime
    prime.push_back(2);
    checkprime[0]=true;
    checkprime[1]=true;
    for(ll i = 4; i<=maxn; i+=2)checkprime[i] = true;
    for (ll i = 3; i <= maxn; i += 2) {
        if (!checkprime[i]) {
            prime.push_back(i);
            for (ll j = i * i; j <= maxn; j += (i + i))
                checkprime[j] = true;
        }
    }
}

//DivisorCount using primefactorization
void divisor(ll n){
    ll N = n;
    ll ans = 1;
    for(ll i = 0; i<prime.size() and prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            ll cnt = 0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            ans*=(cnt+1);
        }
    }
    if(n!=1)ans*=2;
    divi[N] = ans;
}
void task(){
    ll x; cin >> x;
    cout << divi[x] << endl;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    fill(divi, divi+maxn, 0);
    for(ll i = 1; i<=maxn; i++){
        divisor(i);
    }
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
