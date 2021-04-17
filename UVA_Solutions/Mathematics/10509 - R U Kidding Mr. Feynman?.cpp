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
const int maxn = 200005;
const int mod = 1000000007;
/*
n^1/3 = a+dx
dx= (n-a^3)/(3*a^2)
a = n^1/3
*/
void task(){
    sp(4);
    long double n,a,dx;
    while(cin >> n){
        if(n==0 )break;
        a = floor(pow(n,1.0/3.0) + 0.000000000001);
        dx = (n-(a*a*a))/(3*a*a);
        cout << a+dx << endl;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1;// cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
