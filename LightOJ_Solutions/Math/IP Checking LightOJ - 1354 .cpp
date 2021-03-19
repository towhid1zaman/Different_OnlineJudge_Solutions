/*
これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました
*/
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

string tod(string s){
    int n = 0;
    reverse(all(s));
    for(int i = 0; i<s.size(); i++){
        n += pow(2, i) * (s[i] - '0');
    }
    string N = to_string(n);
    return N;
}
void task(){
    string d, b; cin >> d >> b;
    std::vector<string> D;
    string now = "";
    int cnt = 0;
    for(int i = 0; i<d.size(); i++){
        if(d[i] == '.'){
            D.push_back(now);
            now = "";
            cnt++;
        }
        else now+=d[i];

        if(i == d.size()-1){
            D.push_back(now);
        }
    }
    now = "";
    std::vector<string>B;
    for(int i = 0; i<b.size(); i++){
        if(b[i] == '.'){
            B.push_back(tod(now));
            now = "";
        }
        else now+=b[i];

        if(i==b.size() - 1){
            B.push_back(tod(now));
        }
    }
    for(int i = 0; i<D.size(); i++){
        if(D[i] != B[i]){
            cout << "No"<<endl;
            return;
        }
    }
    cout << "Yes"<<endl;
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
