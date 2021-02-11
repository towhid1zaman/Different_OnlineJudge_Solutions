/*
これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました
*/
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
    std::vector<int> ans;
    if(n%2){
        for(int i = 1; i<=n; i+=2){
            ans.push_back(i);
        }
        for(int i = 2; i<=n; i+=2){
            ans.push_back(i);
        }
    }
    else{
        for(int i = 2; i<=n; i+=2){
            ans.push_back(i);
        }
        for(int i = 1; i<=n; i+=2){
            ans.push_back(i);
        }
    }
    bool ok = 0;
    for(int i = 0; i<n-1; i++){
        if(abs(ans[i] - ans[i+1]) == 1){
            ok = true;
            break;
        }
    }
    if(n==2)ok = true;
    if(ok){
        cout << "NO SOLUTION" << endl;
        return;
    }
    for(int x:ans)cout << x << ' ';
        cout << endl;
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
