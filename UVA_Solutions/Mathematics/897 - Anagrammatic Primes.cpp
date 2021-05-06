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

std::vector<int>AnaPrime;
bool isPrime[10000001];

bool allperm(int n){
    string s = to_string(n);
    int cnt = count(all(s), 0);
    cnt+= count(all(s), 2);
    cnt+= count(all(s), 4);
    cnt+= count(all(s), 6);
    cnt+= count(all(s), 8);
    if(cnt>0){
      return false;
    }

    bool ok = true;

    sort(all(s));
    do{
      int N = to_int(s);
      if(!isPrime[N]){
        ok = false;
        break;
      }
    }while(next_permutation(all(s)));

    return ok;
}
void sieve(){
    int N = 10000001, sq = sqrt(N);
    memset(isPrime, true, sizeof isPrime);
    for(int i = 4; i<=N; i+=2){
        isPrime[i] = 0;
    }
    for(int i = 3; i<=sq; i+=2){
        if(isPrime[i]){
            for(int j = i*i; j<=N; j+=i){
                isPrime [j] = 0;
            }
        }
    }
    isPrime[1] = 0;
    isPrime[0] = 0;
    AnaPrime.push_back(2);
    for(int i = 3; i<=N; i+=2){
        if(isPrime[i]){
            if(allperm(i)){
              AnaPrime.push_back(i);
            }
        }
    }
}

void task(){
    int n;
    while(cin >> n){
      if(!n)break;
      bool ok = 0;
      for(int x:AnaPrime){
        string s = to_string(x), t = to_string(n);
        if(x > n and s.size() == t.size()){
          ok = 1;
          cout << x << endl;
          break;
        }
      }
      if(!ok)cout << 0 << endl;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
