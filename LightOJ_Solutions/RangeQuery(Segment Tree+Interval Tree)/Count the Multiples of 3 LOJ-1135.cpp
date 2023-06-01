#include<iostream>
using namespace std;

#define MAXN 100005

struct info {
	int rem[3];
	int lazy;
};
info tree[MAXN * 4];

int left(int node) { return node * 2 + 1; }
int right(int node) { return node * 2 + 2; }
int half(int left, int right) { return left + (right - left) / 2; }

void build(int node, int b, int e) {
	if (b > e)return;
	if (b == e) {
		tree[node].rem[0] = 1;
		tree[node].rem[1] = tree[node].rem[2] = tree[node].lazy = 0;
		return;
	}
	int mid = half(b, e);
	build(left(node), b, mid);
	build(right(node), mid + 1, e);

	for (int i = 0; i < 3; i++) {
		tree[node].rem[i] = tree[left(node)].rem[i] + tree[right(node)].rem[i];
	}
	tree[node].lazy = 0;
}

void propagate(int node, int b, int e) {
	if (!tree[node].lazy) return;
	if (tree[node].lazy == 1) {
		tree[node].rem[2] = tree[node].rem[1];
		tree[node].rem[1] = tree[node].rem[0];
		tree[node].rem[0] = (e - b + 1) - (tree[node].rem[2] + tree[node].rem[1]);
	}
	else {
		tree[node].rem[1] = tree[node].rem[2];
		tree[node].rem[2] = tree[node].rem[0];
		tree[node].rem[0] = (e - b + 1) - (tree[node].rem[2] + tree[node].rem[1]);
	}

	if (b != e) {
		tree[left(node)].lazy += tree[node].lazy;
		tree[left(node)].lazy %= 3;

		tree[right(node)].lazy += tree[node].lazy;
		tree[right(node)].lazy %= 3;
	}

	tree[node].lazy = 0;
}

void update(int node, int b, int e, int l, int r, int newVal) {
	propagate(node, b, e);

	if (e < l || b > r)return;
	if (b >= l && e <= r) {
		tree[node].lazy += newVal;
		propagate(node, b, e);
		return;
	}
	int mid = half(b, e);
	update(left(node), b, mid, l, r, newVal);
	update(right(node), mid + 1, e, l, r, newVal);

	for (int i = 0; i < 3; i++) {
		tree[node].rem[i] = tree[left(node)].rem[i] + tree[right(node)].rem[i];
	}
}

int query(int node, int b, int e, int l, int r) {

	propagate(node, b, e);

	if (e < l || b > r)return 0;
	if (b >= l && e <= r) {
		return tree[node].rem[0];
	}
	int mid = half(b, e);
	return query(left(node), b, mid, l, r) + query(right(node), mid + 1, e, l, r);
}

void solve(int t) {
	cout << "Case " << t << ":" << endl;

	int n, q; cin >> n >> q;
	n -= 1;
	build(0, 0, n);
	while (q--) {
		int cmnd, l, r; cin >> cmnd >> l >> r;
		if (cmnd == 0) {
			update(0, 0, n, l, r, 1);
		}
		else {
			int ans = query(0, 0, n, l, r);
			cout << ans << endl;
		}
	}

}
int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}
}
