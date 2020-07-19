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
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const int INF = 1e9 + 10;
const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

void forw(int r, int c, int incr)
{
    while(incr--){
        cout<<++r<<" "<<++c<<endl;
    }
}
void rev(int r, int c, int dec)
{
    while(dec--){
        cout<<--r<<" "<<--c<<endl;
    }
}
int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            int r, c;
            cin >>r>>c;
            if(r==c && r==1 && c==1)
        {
            cout<<38<<endl;
            int tempr = r;
            int tempc = c;
            int incr = min(8-tempr, 8-tempc);
            int dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<2<<" "<<2<<endl;
            cout<<1<<" "<<3<<endl;
            tempr = 1;
            tempc = 3;
             incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<2<<" "<<4<<endl;
            cout<<1<<" "<<5<<endl;
            tempr = 1;
            tempc = 5;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<2<<" "<<6<<endl;
            cout<<1<<" "<<7<<endl;
            tempr = 1;
            tempc = 7;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<5<<" "<<5<<endl;
            cout<<2<<" "<<2<<endl;
            cout<<3<<" "<<1<<endl;
            tempr = 3;
            tempc = 1;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<4<<" "<<2<<endl;
            cout<<5<<" "<<1<<endl;
            tempr = 5;
            tempc = 1;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<6<<" "<<2<<endl;
            cout<<7<<" "<<1<<endl;
            tempr = 7;
            tempc = 1;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
        }
        else if(r==c && r!=1&& c!=1)
        {
            cout<<39<<endl;
            cout<<1<<" "<<1<<endl;
            r=1,c=1;
            int tempr = r;
            int tempc = c;
            int incr = min(8-tempr, 8-tempc);
            int dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<2<<" "<<2<<endl;
            cout<<1<<" "<<3<<endl;
            tempr = 1;
            tempc = 3;
             incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<2<<" "<<4<<endl;
            cout<<1<<" "<<5<<endl;
            tempr = 1;
            tempc = 5;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<2<<" "<<6<<endl;
            cout<<1<<" "<<7<<endl;
            tempr = 1;
            tempc = 7;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<5<<" "<<5<<endl;
            cout<<2<<" "<<2<<endl;
            cout<<3<<" "<<1<<endl;
            tempr = 3;
            tempc = 1;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<4<<" "<<2<<endl;
            cout<<5<<" "<<1<<endl;
            tempr = 5;
            tempc = 1;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<6<<" "<<2<<endl;
            cout<<7<<" "<<1<<endl;
            tempr = 7;
            tempc = 1;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
        }
        else if(r!=c)
        {
            cout<<40<<endl;
            cout<<(r+c)/2<<" "<<(r+c)/2<<endl;
            r=1,c=1;
            cout<<1<<" "<<1<<endl;
            int tempr = r;
            int tempc = c;
            int incr = min(8-tempr, 8-tempc);
            int dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<2<<" "<<2<<endl;
            cout<<1<<" "<<3<<endl;
            tempr = 1;
            tempc = 3;
             incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<2<<" "<<4<<endl;
            cout<<1<<" "<<5<<endl;
            tempr = 1;
            tempc = 5;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<2<<" "<<6<<endl;
            cout<<1<<" "<<7<<endl;
            tempr = 1;
            tempc = 7;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<5<<" "<<5<<endl;
            cout<<2<<" "<<2<<endl;
            cout<<3<<" "<<1<<endl;
            tempr = 3;
            tempc = 1;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<4<<" "<<2<<endl;
            cout<<5<<" "<<1<<endl;
            tempr = 5;
            tempc = 1;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
            cout<<6<<" "<<2<<endl;
            cout<<7<<" "<<1<<endl;
            tempr = 7;
            tempc = 1;
            incr = min(8-tempr, 8-tempc);
             dec = min(tempr-1, tempc-1);
            forw(tempr,tempc,incr);
            rev(tempr,tempc, dec);
        }
    }




return 0;
}





