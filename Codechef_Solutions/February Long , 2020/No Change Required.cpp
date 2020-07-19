#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define sz(x) (int)x.size()

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

int main(){
        _ios;

        int T;cin>>T;
        while(T--){
            ll n,p;cin>>n>>p;
            vll v(n);
            ll chek = 0;
            rep(i,n){
                cin>>v[i];
                if(p%v[i]==0 and v[i]!=p){
                    chek = v[i];
                }
            }
            bool f = false;
            vll res(n,0);
            rep(i,n){
                if(p%v[i]!=0){
                    f = true;
                    res[i] =  ceil(p/(long double)v[i]);
                    break;
                }
            }
            if(f==true){
                cout<<"YES ";
                rep(i,n)cout<<res[i]<<" ";
                cout<<endl;
            }
            else{
                f = false;
                    rep(i,n-1){
                        if((p-v[i+1] )%v[i]!=0){
                        res[i]  = ceil((p-v[i+1])/(long double)v[i]);
                        res[i+1] = 1;
                        f = true;
                        break;
                    }
                }
                    if(f==true){
                    cout<<"YES ";
                    rep(i,n){
                        cout<<res[i]<<" ";
                    }
                    cout<<endl;
                }
                else cout<<"NO"<<endl;
            }

        }



return 0;
}






