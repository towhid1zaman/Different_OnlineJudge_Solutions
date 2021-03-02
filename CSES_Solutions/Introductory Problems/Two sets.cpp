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
    ll n; cin >> n;
    ll tot = (n*(n+1))/2;
    if(tot%2){
        cout << "NO"<<endl;
        return;
    }
    ll half = tot/2;

    cout << "YES"<<endl;
    std::vector<ll>f, s;
    std::map<ll,bool> mp;

    std::vector<ll> v(n);
    for(int i = 1; i<=n; i++) v[i-1] = i;
    ll l = n, sum = 0, now;
    while(true){
        f.push_back(l);
        mp[l] = 1;
        sum+=l--;
        now = half - sum;
        if(now == 0)break;
        if(now <= l){
            f.push_back(now);
            mp[ now ] = 1;
            break;
        }
    }

    for(int i = 0; i<n; i++){
        if(!mp[ v[i] ])s.push_back(v[i]);
    }

    cout << f.size() << endl;
    for(auto x: f)cout << x <<' ';
    cout << endl;
    cout << s.size() << endl;
    for(auto x: s)cout << x <<' ';

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
