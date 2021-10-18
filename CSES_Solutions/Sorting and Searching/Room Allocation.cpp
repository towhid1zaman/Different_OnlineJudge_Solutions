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

void task(){
    int n; cin >> n;
    std::vector< pair<pair<int, int>, int> > v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    //dbug(v);
    priority_queue< pair<int, int> > q; // greater first(we need smaller, so passed -ve value)
    std::vector<int> ans(n, 0);
    int k = 0,last_room = 0;
    for(int i = 0; i<n; i++){
        int cur_come = v[i].first.first, cur_leave = v[i].first.second;
        int cur_person = v[i].second;
        if(q.empty()){
            last_room++;
            q.push({-cur_leave, last_room});
            ans[cur_person] = last_room;
        }
        else{            
            auto mn = q.top();
            int last_leave = -mn.first, last_person_room = mn.second;
            if(last_leave < cur_come){
                q.pop();
                q.push({-cur_leave, last_person_room});
                ans[cur_person] = last_person_room;
            }
            else{
                last_room++;
                q.push({-cur_leave,last_room});
                ans[cur_person] = last_room;
            }
        }
        k = max(k, (int)q.size());
    }
    cout << k << endl;
    for(auto x:ans)cout << x <<' ';cout << endl;
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
