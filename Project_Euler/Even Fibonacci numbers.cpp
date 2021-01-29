#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;
/*
Problem statement: By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
find the sum of the even-valued terms.

Sequence, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

*/
void task(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    for(int i = 2; ; i++){
        int now = v[i-1] + v[i-2];
        if(now > 4000000)break;
        else v.push_back(now);
    }

    ll ans = 0;
    for(int i = 0; i<v.size(); i++){
        if(v[i]%2==0){
            ans+=v[i];
        }
    }
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
