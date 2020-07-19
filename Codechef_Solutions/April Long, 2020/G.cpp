
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int m = 998244353; // (int)1e9+7
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

ll bxp(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1){
                res=(res*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

ll m_inverse(ll a){
	return bxp(a,m-2);
}

void task(){
    string s; cin >> s;
    ll n = sz(s);
    s='$'+s;
    vector<vector<pair<ll,ll>>> len(n+1);
    stack<ll>st;
    vector<char>oprt(n+5);
    rep1(i,1,n){
        if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')'){
            ll tp = st.top();
            st.pop();
            len[i-tp+1].pb({tp,i});
        }
        else if(s[i]!='#'){
            oprt[st.top()]=s[i];
        }
    }

    ll chek[n+5][10];
    fill(chek);

    ll cnt = 0;
    rep1(i,1,n){
      if(s[i] == '#'){
       cnt++;
       rep(j,4)chek[i][j] = 1;
      }
    }

    rep1(i,1,n){
    for(auto u:len[i]){
       ll left = u.ff+1;
       ll right = u.ss-1;
       char ore = oprt[left-1];
       ll a=0,b=0,c=0,d=0;

       // for and
       if(ore == '&'){
        // if i take # equal to 0
        rep(j,4){
         a = (a + (chek[left][0]*chek[right][j])%m)%m;
        }

        // if i take # equal to 1
         a = (a + (chek[left][1]*chek[right][0])%m)%m;
         b = (b + (chek[left][1]*chek[right][1])%m)%m;
         c = (c + (chek[left][1]*chek[right][2])%m)%m;
         d = (d + (chek[left][1]*chek[right][3])%m)%m;

        // if i take # equal to a
         a = (a + (chek[left][2]*chek[right][0])%m + (chek[left][2]*chek[right][3])%m)%m;
         c = (c + (chek[left][2]*chek[right][1])%m + (chek[left][2]*chek[right][2])%m)%m;

        // if i take # equal to A
         a = (a + (chek[left][3]*chek[right][0])%m + (chek[left][3]*chek[right][2])%m)%m;
         d = (d + (chek[left][3]*chek[right][1])%m + (chek[left][3]*chek[right][3])%m)%m;
        }

       // for or
       if(ore == '|'){
        // if i take # equal to 0
         a = (a + (chek[left][0]*chek[right][0])%m)%m;
         b = (b + (chek[left][0]*chek[right][1])%m)%m;
         c = (c + (chek[left][0]*chek[right][2])%m)%m;
         d = (d + (chek[left][0]*chek[right][3])%m)%m;
        // for 1
         rep(j,4){
          b = (b + (chek[left][1]*chek[right][j])%m)%m;
         }
        // for 2
         c = (c + (chek[left][2]*chek[right][0])%m + (chek[left][2]*chek[right][2])%m)%m;
         b = (b + (chek[left][2]*chek[right][1])%m + (chek[left][2]*chek[right][3])%m)%m;
        // for 3
         d = (d + (chek[left][3]*chek[right][0])%m + (chek[left][3]*chek[right][3])%m)%m;
         b = (b + (chek[left][3]*chek[right][1])%m + (chek[left][3]*chek[right][2])%m)%m;
       }
       // for xor
       if(ore == '^'){
        // for 0
         a = (a + (chek[left][0]*chek[right][0])%m)%m;
         b = (b + (chek[left][0]*chek[right][1])%m)%m;
         c = (c + (chek[left][0]*chek[right][2])%m)%m;
         d = (d + (chek[left][0]*chek[right][3])%m)%m;
        // for 1
         a = (a + (chek[left][1]*chek[right][1])%m)%m;
         b = (b + (chek[left][1]*chek[right][0])%m)%m;
         c = (c + (chek[left][1]*chek[right][3])%m)%m;
         d = (d + (chek[left][1]*chek[right][2])%m)%m;
        // for 2
         a = (a + (chek[left][2]*chek[right][2])%m)%m;
         b = (b + (chek[left][2]*chek[right][3])%m)%m;
         c = (c + (chek[left][2]*chek[right][0])%m)%m;
         d = (d + (chek[left][2]*chek[right][1])%m)%m;
        // for 3;
         a = (a + (chek[left][3]*chek[right][3])%m)%m;
         b = (b + (chek[left][3]*chek[right][2])%m)%m;
         c = (c + (chek[left][3]*chek[right][1])%m)%m;
         d = (d + (chek[left][3]*chek[right][0])%m)%m;
       }
       chek[left-1][0] = chek[right+1][0] = a;
       chek[left-1][1] = chek[right+1][1] = b;
       chek[left-1][2] = chek[right+1][2] = c;
       chek[left-1][3] = chek[right+1][3] = d;
    }
}

     ll tmp = bxp(4,cnt);
     ll inv = m_inverse(tmp);

    rep(j,4){
        cout<<(chek[1][j]*inv)%m<<" ";
    }
    cout<<endl;
 }
int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            task();
        }


return 0;
}

