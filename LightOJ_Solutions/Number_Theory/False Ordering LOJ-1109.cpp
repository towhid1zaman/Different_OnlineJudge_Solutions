#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

std::map<int,int> mp;
std::vector<int>v;
bool cmp(int x, int y){
    return ((mp[x] < mp[y]) or (mp[x] == mp[y] and x>y));
}
void pre(){
    for(int d = 1; d<=1000; d++){
        for(int i = d; i<=1000; i+=d){
            mp[i]++;
        }
    }
    for(int i = 1; i<=1000; i++){
        v.push_back(i);
    }
    sort(all(v), cmp);
}
void task(){
    int n; cin >> n;
    cout << v[n-1]<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    pre();
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
