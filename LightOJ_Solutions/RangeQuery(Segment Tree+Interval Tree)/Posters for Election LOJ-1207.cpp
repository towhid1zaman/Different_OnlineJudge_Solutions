#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000006

int nums[MAXN];
int tree[4 * MAXN];
int lazy[4 * MAXN];
int l[2*MAXN], r[2*MAXN];

int left(int node) { return node * 2 + 1; }
int right(int node) { return node * 2 + 2; }
int half(int left, int right) { return left + (right-left)/2; }

void propagate(int node, int b, int e) {
	if (lazy[node] > 0) {
		tree[node] = lazy[node];
		if (b != e) {
			lazy[left(node)] = lazy[node];
			lazy[right(node)] = lazy[node];
		}
		lazy[node] = 0;
	}
}
void updateRange(int node, int b, int e, int l, int r, int newVal) {
	propagate(node, b, e);
	if (e < l || b > r)return;
	if (b >= l && e <= r) {
		lazy[node] = newVal;
		propagate(node, b, e);
		return;
	}
	int mid = half(b, e);
	updateRange(left(node), b, mid, l, r, newVal);
	updateRange(right(node), mid + 1, e, l, r, newVal);
}

int query(int node, int b, int e, int l, int r) {
	propagate(node, b, e);

	if (e < l || b > r)return 0;
	if (b >= l && e <= r) {
		return tree[node];
	}
	int mid = half(b, e);
	return query(left(node), b, mid, l, r) + query(right(node), mid + 1, e, l, r);
}
void reset() {
	memset(tree, 0, sizeof tree);
	memset(lazy, 0, sizeof lazy);
}
void solve(int t) {

	int q; cin >> q;
	set<int>unq;
	for (int i = 0; i < q; i++) {
		cin >> l[i] >> r[i];
		unq.insert(l[i]);
		unq.insert(r[i]);
	}

	int id = -1;
	unordered_map<int, int>compress;
	for (auto u : unq) {
		compress[u] = ++id;
	}

	for (int i = 0; i < q; i++) {
		int L = compress[l[i]];
		int R = compress[r[i]];
		updateRange(0, 0, id, L, R, i + 1);
	}
	set<int>ans;
	for (int i = 0; i <= id; i++) {
		int val = query(0, 0, id, i, i);
		if (val != 0)ans.insert(val);
	}

	cout << "Case " << t << ": " << ans.size() << endl;
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		reset();
		solve(t);
	}
}

