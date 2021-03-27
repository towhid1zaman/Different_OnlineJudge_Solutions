/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
#define endl "\n"
#define pb push_back
#define rep(i,a) for(int i=0;i<a;i++)
#define all(v) (v).begin(),(v).end()
const int maxn = 200005;
const int mod = 1000000007;
#define sp(k) cout<<setprecision(k)<<fixed;

void task(){
    int n; cin >> n;
    double a_0, a_n1;
    cin >> a_0;
    cin >> a_n1;
    double ans = n*a_0+a_n1, temp = 0.0,c_i;
    for(int i = 0; i<n; i++){
        cin >> c_i;
        temp+=c_i;
        ans-=2*temp;
    }
    cout << (ans/(n+1))<<endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sp(2);
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
        if(__ <T)cout << endl;
    }
      
return 0;
}
