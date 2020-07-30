
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
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
const int maxn = 5000005;
ll phi[maxn];
void phiGen(){
    for(int p = 2; p<=maxn; p++){
        if(!phi[p]){
            phi[p] = p-1;
            for(int i=2*p; i<=maxn; i+=p){
                if(!phi[i])phi[i]=i;
                phi[i]/=p;
                phi[i] *=(p-1);
            }
        }
    }
    for(int i = 2; i<maxn;i++){
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
}

void task(){
    int a,b; //cin >> a >> b;
    scanf("%d%d",&a,&b);
    cout << phi[b] - phi[a-1]<<endl;
}
int cs = 1;
int main(){
        //_
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif
        phiGen();
        int T = 1; cin >> T;
        while(T--){
            cout << "Case "<<cs++<<": ";
            task();
        }
        
return 0;
}
