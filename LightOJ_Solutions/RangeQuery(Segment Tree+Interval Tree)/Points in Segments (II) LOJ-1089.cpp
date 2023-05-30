#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 50000
#define maxNode 50000
int x[3*MAXN], y[3*MAXN], qr[3*MAXN];
int tree[maxNode*4*3];
int lazy[maxNode*4*3];

int left(int node) { return node * 2 + 1; }
int right(int node) { return node * 2 + 2; }
int half(int left, int right) { return left + (right - left) / 2; }

void propagate(int node, int b, int e) {
	if (lazy[node] > 0) {
		tree[node] += (e - b + 1)*lazy[node];
		if (b != e) {
			lazy[left(node)] += lazy[node];
			lazy[right(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int b, int e, int l, int r, int newVal){
	propagate(node, b, e);

	if (e < l || b > r)return;
	if (b >= l && e <= r) {
		lazy[node] = newVal;
		propagate(node, b, e);
		return;
	}

	int mid = half(b, e);
	update(left(node), b, mid, l, r, newVal);
	update(right(node),mid + 1,e, l, r, newVal);
	tree[node] = tree[left(node)] + tree[right(node)];
}


int query(int node, int b, int e, int l, int r) {
	propagate(node, b, e);
	if (e < l || b > r)return 0;
	if (b >= l && e <= r) {
		return tree[node];
	}
	int mid = half(b, e);
	int x = query(left(node), b, mid, l, r);
	int y = query(right(node), mid + 1, e, l, r);
	return x + y;
}

void reset(){
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(qr, 0, sizeof qr);
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
}
void solve(int t) {
    reset();
	cout << "Case " << t << ":"<<endl;
	int n, q; cin >> n >> q;
	unordered_map<int, int>mark;
	set<int>val;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		val.insert(x[i]);
		val.insert(y[i]);

	}
	for(int i = 0; i < q; i++){
        cin >> qr[i];
        val.insert(qr[i]);
	}

	int limit = 0;
	for(auto x:val){
        mark[x] = limit++;
	}
	for(int i = 0; i < n; i++){
        int l = mark[x[i]];
        int r = mark[y[i]];
        update(0, 0, limit, l, r, 1);
	}
	for(int i = 0; i < q; i++){
        int ans = query(0, 0, limit, mark[qr[i]], mark[qr[i]]);
        cout << ans << endl;
	}
}

main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}
}
