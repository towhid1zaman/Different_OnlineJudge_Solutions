#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef  unsigned long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;
/*
Problem statement: Find the largest palindrome made from the product of two 3-digit numbers.

*/
///Convert int to string
template <typename T>
string to_str(T str)
{
    stringstream stream;
    stream << str;
    return stream.str();
}
bool chek(ll n){
    string s = to_str(n);
    string t = s;
    reverse(all(t));
    return s==t;
}
void task(){
    ll ans = 0;
    for(ll i = 100; i<=999; i++){
        for(ll j = 100; j<=999; j++){
            ll Now = i*j;
            if(chek(Now)){
                ans = max(ans, Now);
            }
        }
    }
    cout << ans <<endl;
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
