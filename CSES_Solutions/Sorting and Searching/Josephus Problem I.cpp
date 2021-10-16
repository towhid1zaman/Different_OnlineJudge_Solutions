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
    int n; cin >> n;
    std::vector<int> child;
    for(int i = 1; i<=n; i++)child.push_back(i);
    while((int)child.size() > 1){
        std::vector<int> alive;
        for(int i = 0; i<child.size(); i++){
            if(i%2)cout << child[i]<<' ';
            else alive.push_back(child[i]);
        }
        int sz = (int)child.size();
        if(sz%2==0)child = alive;
        else{
            int cur_first = alive.back();
            alive.pop_back();
            child.clear();
            child.push_back(cur_first);
            for(auto c:alive)child.push_back(c);
        }
    }
    cout << child[0] << endl;
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
