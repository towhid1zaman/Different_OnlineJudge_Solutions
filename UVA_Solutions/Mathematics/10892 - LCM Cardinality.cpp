#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;
ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a, ll b){
    return a/ gcd(a,b)*b;
}
void task(){
    ll n;
    while(cin >> n){
        if(n==0)break;
        std::vector<ll>div;
        for(ll i = 1; i*i<=n; i++){
            if(n%i==0){
                div.push_back(i);
                if(i != n/i)div.push_back(n/i);
            }
        }
        sort(all(div));
        int ans = 0;
        for(int i = 0; i<div.size(); i++){
            for(int j = 0; j<i;j++){
                if(lcm(div[i], div[j]) == n){
                    ans++;
                }
            }
        }
        cout << n<<' '<<ans+1 << endl;
        div.clear();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
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
