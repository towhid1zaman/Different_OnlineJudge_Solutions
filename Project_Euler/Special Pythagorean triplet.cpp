#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

/*
problem statement: There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/
bool triple(int a, int b, int c){
    return (a*a) + (b*b) == (c*c);
}
void task(){
    int n = 1000;
    int ans = 0;
    for(int a = 0; a<=n; a++){
        for(int b = 0; b<=n; b++){
            for(int c = 0; c<=n; c++){
                if(triple(a,b,c) and (a+b+c)==n){
                    ans = max(ans,a*b*c);
                }
            }
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
