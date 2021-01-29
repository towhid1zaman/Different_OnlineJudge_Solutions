#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;
/*
Problem statement: ind the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum

*/
ll square(ll x){
    return x*x;
}
void task(){
    ll sumof_square = 0;
    for(ll i = 1; i<=100;i++){ // also can be done = (n*(n+1)*(2*n+1))/6
        sumof_square+=square(i);
    }
    ll squareSum = (100*(100+1))/2;
    squareSum = square(squareSum);

    cout << squareSum - sumof_square << endl;
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
