#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 100000;
const int mod = 1000000007;
int fa[maxn];
int sz[maxn];

int Find(int x){ 
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}

void task(){
    int n; cin >> n;
    
    for(int i = 0; i<=maxn; i++){
        fa[i] = i;
        sz[i] = 1;
    }
    int pos = 0;
    std::map<string, int> mp;
    for(int i = 0; i<n; i++){
        string a, b; cin >> a >> b;
        if(mp[a] == 0)mp[a] = ++pos;
        if(mp[b] == 0)mp[b] = ++pos;
        int x = Find(mp[a]), y = Find(mp[b]);
        if(x!=y){
            fa[y] = x;
            sz[x] += sz[y];
            cout << sz[x]<<endl;
        }
        else cout << sz[x]<<endl;
    }
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
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
