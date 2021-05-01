#include <bits/stdc++.h>
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

int charToint(char c){
  if(c<='9' and c>='0')return c - '0';
  else return c - 'A' + 10;
}

char intTochar(int n){
  if(n<=9)return n+'0';
  else return 'A' + (n-10);
}

ll convertToDecimal(string &s, int base){
    int n = s.size();
    ll number = 0;
    for(int i = 0; i<n; i++){
      number = (number * base) + charToint(s[i]);
    }
    return number;
}
ll convertToDecimal_MOD(string &s, int base, int Mod){
    int n = s.size();
    ll number = 0;
    for(int i = 0; i<n; i++){
      number = (number * base) + charToint(s[i]);
      number%=Mod;
    }
    return number%Mod;
}
string Decimal_to_AnyBase(ll n,int base){
    string ans;
    while(n!=0){
      ans.push_back(intTochar(n%base));
      n/=base;
    }
    if(ans.empty())ans.push_back('0');
    reverse(all(ans));
    return ans;
}

bool isValidBase(string s, int base){
  int n = s.size();
  int ok = 0;
  for(int i = 0; i<n; i++){
    if(charToint(s[i]) >= base)ok = 1;
  }
  return ok;
}

void task(){
    int b;
    string s, m;
    while(cin >> b >> s >> m){
      int mod = convertToDecimal(m, b);
      ll N = convertToDecimal_MOD(s, b, mod);
      cout << Decimal_to_AnyBase(N, b) << endl;
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
