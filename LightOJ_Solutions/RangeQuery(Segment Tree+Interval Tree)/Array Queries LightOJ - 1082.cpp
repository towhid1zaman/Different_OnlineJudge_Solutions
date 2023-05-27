//Using sqrt decomposition

#include<bits/stdc++.h>

using namespace std;
#define MAXN 100005
#define blockSize 300

int nums[MAXN];
int block[MAXN];
void build(int n) {
	for (int i = 0; i < n; i++) {
		block[i / blockSize] = min(block[i / blockSize], nums[i]);
	}
}
int query(int l, int r) {
	int ans = INT_MAX;
	for (int i = l; i <= r;) {
		if (i % blockSize == 0 && i + blockSize - 1 <= r) {
			ans = min(ans, block[i / blockSize]);
			i += blockSize;
		}
		else {
			ans = min(ans, nums[i]);
			i++;
		}
	}
	return ans;
}
void solve(int t) {
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	build(n);
	cout << "Case " << t << ":" << endl;
	while (q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		int ans = query(l, r);
		cout << ans << endl;
	}
}
void reset() {
	for (int i = 0; i <= MAXN; i++) {
		block[i] = INT_MAX;
		nums[i] = 0;
	}
}
int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++){
		reset();
		solve(t);
	}
}


//Using segment tree

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
const int maxn = 1000100;
const int INF = 1e10+1;
int a[maxn];
int tree[4*maxn];

void Build(int node, int b, int e){
    if(b==e){
        tree[node] = a[b];
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid = (b+e)/2;
    Build(left,b,mid);
    Build(right,mid+1,e);
    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j){
    if(i > e or j<b){
        return INF;
    }
    if(b>=i and e<=j) return tree[node];
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return min(p1,p2);
}
int main(){
        _ios;

        int T;cin>>T;
        for(int i = 1;i<=T;i++){
            int n,m;
            fill(a),fill(tree);
            cin>>n>>m;
            for(int i = 1; i<=n;i++){
                cin>>a[i];
            }
            Build(1,1,n);
            cout<<"Case "<<i<<":"<<endl;
            while(m--){
                int i,j;
                cin>>i>>j;
                cout<<query(1,1,n,i,j)<<endl;
            }
        }

return 0;
}
