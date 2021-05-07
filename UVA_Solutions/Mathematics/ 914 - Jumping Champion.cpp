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

template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbug(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}



const double pi = acos(-1.0);
const int maxn = 1000001;
const int mod = 1000000007;

///Convert int to string
template <typename T>
string to_str(T str)
{
    stringstream stream;
    stream << str;
    return stream.str();
}

///Convert string to int
template <typename T>
int to_int(T num)
{
    int val;
    stringstream stream;
    stream << num;
    stream >> val;
    return val;
}

std::vector<int>prime;
bool isPrime[maxn];

void sieve(){
    int N = maxn, sq = sqrt(N);
    memset(isPrime, true, sizeof isPrime);
    for(int i = 4; i<=N; i+=2){
        isPrime[i] = 0;
    }
    for(int i = 3; i<=sq; i+=2){
        if(isPrime[i]){
            for(int j = i*i; j<=maxn; j+=i){
                isPrime [j] = 0;
            }
        }
    }
    isPrime[1] = 0;
    isPrime[0] = 0;
    prime.push_back(2);
    for(int i = 3; i<=maxn; i+=2){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
}

void task(){
    int l, r; cin >> l >> r;
    int pl = lower_bound(all(prime), l) - prime.begin();
    int pr = lower_bound(all(prime), r) - prime.begin();
    if(prime[pr] > r)pr--;
    //dbug(prime[pl], prime[pr]);
    std::map<int, int> mp;
    for(int i = pl+1; i<=pr; i++){
      mp[ prime[i] - prime[i-1] ]++;
    }
    int ans = 0, val = 0;
    int mx_cnt = 0;
    std::vector<int>cnt_ans;
    for(auto x:mp){
      if(x.second > val){
        ans = x.first;
        val = x.second;
      }
    }
    for(auto x:mp){
      if(x.second == val)mx_cnt++;
    }
    //dbug(mp);
    if(ans == 0 or mx_cnt > 1){
      cout <<"No jumping champion"<<endl;
    }
    else{
      cout << "The jumping champion is "<< ans << endl;
    }
    mp.clear();
    cnt_ans.clear();
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
