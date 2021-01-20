#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

// derangement - number of ways

void task(){
    int n; cin >> n;
    std::vector<int>d(n+1, 0);
    d[2] = 1;
    for(int i = 3; i<=n; i++){
        d[i] = (((d[i-1]+d[i-2])%mod)*(i-1))%mod;
    }
    cout << d[n] << endl;
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
