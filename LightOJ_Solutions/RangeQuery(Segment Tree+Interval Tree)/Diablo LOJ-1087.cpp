#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//#define int long long
#define MAXN 100005


int nums[4 * MAXN];
int vis[4 * MAXN];
int tree[5 * MAXN];


int left(int node) { return 2 * node + 1; }
int right(int node) { return 2 * node + 2; }
int half(int left, int right) { return left + (right - left) / 2; }

void build(int node, int b, int e) {
	if (b > e)return;
	if (b == e) {
		tree[node] = vis[b];
		return;
	}
	int mid = half(b, e);
	build(left(node), b, mid);
	build(right(node), mid + 1, e);
	tree[node] = tree[left(node)] + tree[right(node)];
}

void update(int node, int b, int e, int pos, int newVal) {
	if (b == e) {
		tree[node] = newVal;
		return;
	}
	int mid = half(b, e);
	if (pos <= mid)update(left(node), b, mid, pos, newVal);
	else update(right(node), mid + 1, e, pos, newVal);

	tree[node] = tree[left(node)] + tree[right(node)];
}
int query(int node, int b, int e, int l, int r) {
	if (e < l || b > r)return 0;
	if (l <= b && e <= r) {
		return tree[node];
	}

	int mid = half(b, e);
	int x = query(left(node), b, mid, l, r);
	int y = query(right(node), mid + 1, e, l, r);
	return x + y;
}

void solve(int t) {
	int n, q;  cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		vis[i] = 1;
	}
	int fixed = 2 * n;
	build(0, 0, fixed);
	while (q--) {
		char command; cin >> command;
		if (command == 'c') {

			int pos; cin >> pos;
			int low = 0, high = fixed, ans = -1;
			while (low <= high) {
				int mid = half(low, high);
				int newPos = query(0, 0, fixed, 0, mid);
				if (newPos >= pos) {
					high = mid - 1;
					ans = mid;
				}
				else low = mid + 1;
			}

			if (ans == -1) {
				cout << "none" << endl;
			}
			else {
				cout << nums[ans] << endl;
				update(0, 0, fixed, ans, 0);
			}
		}
		else if (command == 'a') {
			int newVal; cin >> newVal;

			nums[n] = newVal;
			update(0, 0, fixed, n, 1);
			n += 1;
		}
	}



}
void reset() {
	memset(nums, 0, sizeof nums);
	memset(tree, 0, sizeof tree);
	memset(vis, 0, sizeof vis);

}
int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		reset();
		cout << "Case " << t << ":" << endl;
		solve(t);
	}
}
