
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int  maxn = 6000000;
const int  N = 100000005;

vector<bool>isp(N,true);
int  prime[maxn];
unsigned int product[maxn];
int  cnt = 0;
void sieve(){
        for(int  i = 2; i*i<N; i++){
            if(isp[i]){
                for(int j = i*i; j<N; j+=i){
                    isp[j] = false;
                }
            }
        }

        // prefix for fast calculation of product after sqrt(n) primes

        product[0] = 1;
        for(int  i = 2; i<N; i++){
            if(isp[i]){
                prime[cnt++] = i;
                product[cnt] = product[cnt-1]*i;
            }
        }
}

int main(){
        //_ios;
        sieve();
        int T; cin >> T;
        int cs  = 1;
        while(T--){
            int  n; cin >> n;
            unsigned ans = 1;
            for(auto p : prime){
                if(p*p > n) break;
                ll cnt = 0,cur = n;
                while(cur/=p)cnt++;
                cnt--;
                while(cnt--){
                    ans*=p;
                }
            }
            int  idx = upper_bound(prime,prime+cnt,n) - prime;
            ans*=product[idx];

            cout<<"Case "<<cs++<<": "<<ans<<endl;
        }


return 0;
}

