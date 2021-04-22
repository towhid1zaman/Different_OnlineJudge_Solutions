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
const int maxn = 200005;
const int mod = 1000000007;

void task(){
    int n;
    while(cin >> n){
        if(!n)break;
        std::vector<pair<int, int>> v;
        for(int i = 1; i<n; i++){
            v.emplace_back(i,i+1);
        }
        v.emplace_back(n, 1);
        int next =n/2+1;
        for(int i = 1; i<=n/2; i++){
            v.emplace_back(i, next);
            next++;
        }
        int possible_edge = (n*3)/2;
        if(n%2==1 or n== 2 or possible_edge!=v.size()){
            cout << "Impossible" << endl;
        }
        else{
            cout << v.size() << endl;
            for(auto x:v){
                cout <<x.first<<' '<<x.second<<endl;
            }
        }
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
