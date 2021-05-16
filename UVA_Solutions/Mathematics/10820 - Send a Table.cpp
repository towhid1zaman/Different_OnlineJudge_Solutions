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
const int maxn = 51111;
const int mod = 1000000007;

ll phi[maxn];
ll ans[maxn];
void phiGen(int n){
    for(int i = 1; i<=n; i++){
        phi[i] = i;
    }
    for(int p = 2; p<=n; p++){
        if(phi[p]==p){
            phi[p] = p-1;
            for(int i=2*p; i<=n; i+=p){
                phi[i] = (phi[i]/p)*(p-1);
            }
        }
    }
    ans[1] = 1;
    for(int i = 2; i<=maxn; i++){
      ans[i] = ans[i-1] + 2*phi[i];
    }
}

void task(){
   phiGen(maxn);
   ll n;
   while(cin >> n and n){
    cout << ans[n] << endl;
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
