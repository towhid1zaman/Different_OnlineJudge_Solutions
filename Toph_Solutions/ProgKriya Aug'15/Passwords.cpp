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
    string s; while(cin >> s){
        int a = 0, b = 0, c = 0;
        int j = 0;
        int ans = 0;
        for(j = 0;j<=(int)s.size(); j++){
            if(a and b and c){
                ans++;
                a = b = c = 0;
            }
            if(s[j] >='a' and s[j]<='z' and !a)a++;
            else if(s[j] >='A' and s[j]<='Z' and !b)b++;
            else if(s[j] >='0' and s[j]<='9' and !c)c++;
        }
        cout << ans << endl;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
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



