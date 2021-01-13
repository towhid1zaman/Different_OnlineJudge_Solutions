#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;


void task(){
    int n; cin >> n;
    std::vector<ll> v(n);
    ll cnt[1000001]={};
    ll mx = 0;
    for(int i = 0; i<n; i++){
        cin >> v[i]; mx = max(v[i], mx);
        cnt[ v[i] ]++;
    }

    for(int d = mx; d>=1; d--){
        ll dd = 0;
        for(int i = d; i<=mx; i+=d){
            dd+=cnt[i];
        }
        if(dd>=2){
            cout << d << endl;
            return;
        }
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
