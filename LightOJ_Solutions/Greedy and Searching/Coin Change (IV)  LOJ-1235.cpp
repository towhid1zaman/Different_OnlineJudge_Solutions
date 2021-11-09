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
namespace debugging{
    template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
    template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
    template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
    template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
    template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
    #define dbug(args...) do {cerr << #args << " : "; Hooo(args); } while(0)
    void Hooo(){cerr << endl;}
    template<typename T>void Hooo(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
    template<typename T,typename...hello>void Hooo(T arg,const hello&...rest){cerr<<arg<<' ';Hooo(rest...);}
}using namespace debugging;
void subset_sum(int pos, vector<int>a,vector<int>&v,int sum){
    if(pos == a.size()){
        v.push_back(sum);
        return;
    }
    subset_sum(pos+1, a, v, sum); // taking 0 time
    subset_sum(pos+1, a, v, sum+a[pos]); // taking 1 time
    subset_sum(pos+1, a, v, sum+(2*a[pos])); // taking 2 time
}
void task(){
    int n, w; cin >> n >> w;
    vector<int>v1,v2,subset_v1, subset_v2;
    for(int i = 0; i<n; i++){
        ll a; cin >> a;
        if(i%2==0){
                v1.push_back(a);
        }
        else{
                v2.push_back(a);
        }
    }
    subset_sum(0,v1,subset_v1,0);
    subset_sum(0,v2,subset_v2,0);
    sort(all(subset_v2));
    int ans = 0;
    for(ll a:subset_v1){
        if(a == w){
            ans = 1;
            break;
        }
        ll need = w - a;
        bool pos = binary_search(subset_v2.begin(), subset_v2.end(), need);
        if(pos){
            ans = 1;
            break;
        }
    }
    if(ans)cout << "Yes"<<endl;
    else cout << "No" << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
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

