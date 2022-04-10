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
#define unq(v) sort(all(v)),v.erase(unique(all(v)),vec.end());
const double pi = acos(-1.0);
const int maxn = 2000006;
const int mod = 1000000007;


void task(){
        int n, k; cin >> n >> k;
        while(k >= n)k-=n;
        vector<int>v(n);
        for(int i = 0; i<n; i++){
                cin >> v[i];
        }
        for(int i = n-k; i<n; i++){
                cout << v[i]<<' ';
        }
        for(int i = 0; i<n-k; i++){
                cout << v[i]<<' ';
        }
        cout << endl;
}
 
int main(){
    //ctrl+alt+b
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
