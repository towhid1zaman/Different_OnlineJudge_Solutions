/*
これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました
*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 1000005;
const int mod = 1000000007;

ll phi[maxn];
void phiGen(){
    for(int p = 2; p<=maxn; p++){
        if(!phi[p]){
            phi[p] = p-1;
            for(int i=2*p; i<=maxn; i+=p){
                if(!phi[i])phi[i]=i;
                phi[i]/=p;
                phi[i] *=(p-1);
            }
        }
    }
    //for range a to b
    /*
    for(int i = 2; i<maxn;i++){
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
    */
}

void task(){
    ll n;
    std::vector<ll>ans(maxn, 0);
    for(ll i = 2; i<=maxn; i++){
        ans[i] = phi[i];
        ans[i]+=ans[i-1];
    }
    while(true){
        cin >> n;
        if(!n)break;
        cout <<((n >= 2) ? ans[n]: 0) << endl;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    phiGen();
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
