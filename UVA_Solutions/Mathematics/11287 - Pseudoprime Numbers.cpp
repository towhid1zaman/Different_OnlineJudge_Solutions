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


    
ll bigmod(ll a, ll e, ll m) {
    ll ret = 1LL;
    ll aa = (ll)a;
    while (e) {
        if (e&1) {
            ret *= aa;
            if (ret > m)
                ret %= m;
            e--;
        }
        aa *= aa;
        e /= 2;
        if (aa > m)
            aa %= m;
    }
    return ret;
}


void task(){
    ll p, a;
    while(cin >> p >> a){
      if(!p and !a)break;
      if(!isPrime(p) and bigmod(a,p,p) == a)cout << "yes"<<endl;
      else cout << "no"<<endl;
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
