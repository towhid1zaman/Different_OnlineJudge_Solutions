#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;


void task(){
    long long n; cin >> n;
    long long sq = ceil(sqrt(n));
    long long rest = sq*sq - n;
    long long row, col;
    if(rest >= sq){
        col = sq;
        row = n - (sq-1)*(sq-1);
    }
    else{
        col = rest+1;
        row = sq;
    }
    if(sq%2==0)swap(row, col);
    cout <<col <<' '<<row<<endl;
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
