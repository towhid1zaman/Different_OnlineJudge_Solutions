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

const double pi = acos(-1.0);
const int maxn = 2000006;
const int mod = 1000000007;


void task(){
    int n, q; cin >> n >> q;
    vector<int>a(n);
    map<int,int>mp;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        mp[a[i]] = 1;
    }
    while(q--){
        int A, B; cin >> A >> B;
        int ans = 0;
        int x = lower_bound(a.begin(), a.end(), A) - a.begin();
        int y = upper_bound(a.begin(), a.end(), B) - a.begin();
        cout << y - x << endl;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        cout <<"Case "<<__<<":"<<endl;
        task();
    }

return 0;
}

/*
1
5 3
1 4 6 8 10
0 5
6 10
0 0
*/
