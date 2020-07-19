
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair< int, int > pii;
typedef vector<pii>vip;
typedef pair< pii, int > ppi;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;
 
void task(){
     ll n;cin>>n;
     vll a(n),b(n);
     map<ll,ll>m1;
     map<ll,ll>m2;
     map<ll,ll>m3;
     map<ll,ll>m4;
     map<ll,ll>m5;
     rep(i,n){
	     cin>>a[i];
	     m1[a[i]]++;
	     m3[a[i]]++;
     }
     rep(i,n){
	     cin>>b[i];
	     m2[b[i]]++;
	     m3[b[i]]++;
     }
     bool f = false;
     for(auto it:m3){
         if(it.ss%2!=0){
             f=true;
             break;
         }
     }
     vll chek1(n),chek2(n);
     rep(i,n)chek1[i]=a[i];
     rep(i,n)chek2[i]=b[i];
     sort(all(chek1));
     sort(all(chek2));
     bool p = false;
     rep(i,n){
         if(chek1[i]!=chek2[i]){
             p = true;
             break;
         }
     }
     if(p==false)cout<<0<<endl;
     else if(f)cout<<-1<<endl;
     else{
     	ll cnt=0, mn = INT_MAX;
     	vll v1,v2;
     	rep(i,n)mn=min(mn,a[i]);
     	rep(i,n)mn=min(mn,b[i]);
        for(auto it:m1){
            if(it.ss>m2[it.ff])
            m4[it.ff]=(it.ss-m2[it.ff])/2;
        }
        for(auto it:m2){
            if(it.ss>m1[it.ff])
            m5[it.ff]=(it.ss-m1[it.ff])/2;
        }
        for(auto it:m4){
            rep(j,it.ss)
            	v1.pb(it.ff);
        }
        for(auto it:m5){
        	rep(j,it.ss)
            	v2.pb(it.ff);
        }
        sort(all(v1));
        sort(all(v2),greater<int>());
        rep(i,v1.size()){
        	ll cnt1=v1[i];
        	ll cnt2=v2[i];
        	cnt += min(2*mn,(min(cnt1,cnt2)));
        }
        cout << cnt << endl;
	}
}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; cin >> T;
        while(T--){
            task();
        }
        
return 0;
}


