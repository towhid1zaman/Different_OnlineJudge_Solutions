#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;
/*
Problem statement: What is the largest prime factor of the number 600851475143 ?

*/
void task(){
    ll N = 600851475143;
    ll ans = 0;
    for(ll i = 2;i<=sqrt(N); i++){
        if(N%i==0){
            ans = max(ans, i);
            while(N%i==0){
                N/=i;
            }
        }
    }
    if(N>2)ans = max(ans, N);
    cout << ans << endl;
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
