#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

/*
every 3 consicutive numbers figits sum is divisible by 3
means, 123, 345,... x,x+1,x+2 = 3x+3 = 3(x+3)
so, 1 to n, has (n/3) number of tuple and every tuple has 2 number that is fivisible by 3 
so, 1---n => (n/3)*2 number that divisible by 3
corner cases, suppose n = 5, so => (5/3)*2 = 2, but divisible number is 3
so, if n%3==2 then we have to increase ans+=1;
*/
ll cnt(ll n){
    ll ans = (n/3)*2;
    if(n%3==2)ans+=1;
    return ans;
}
void task(){
   ll a, b; cin >> a >> b;
   ll l = cnt(a-1), r = cnt(b);
   cout << r - l << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
