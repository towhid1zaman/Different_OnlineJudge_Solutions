#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int tree[3 * MAXN];
int lazy[3 * MAXN];

int left(int node) { return 2 * node + 1; };
int right(int node) { return 2 * node + 2; };
int half(int left, int right) { return left + (right - left) / 2; };

void reset() {
	memset(tree, 0, sizeof tree);
    memset(lazy, -1, sizeof lazy);
}
void propagate(int node, int b, int e) {
	if (lazy[node] != -1) {
		tree[node] = (e - b + 1) * lazy[node];
		if (b != e) {
			lazy[left(node)] = lazy[node];
			lazy[right(node)] = lazy[node];
		}
		lazy[node] = -1;
	}
}

void update(int node, int b, int e, int l, int r, int newVal) {
	propagate(node, b, e);

	if (e < l || b > r)return;
	if (b >= l && e <= r) {
		lazy[node] = newVal;
		propagate(node, b, e);
		return;
	}

	int mid = half(b, e);
	update(left(node), b, mid, l, r, newVal);
	update(right(node), mid + 1, e, l, r, newVal);
	tree[node] = tree[left(node)] + tree[right(node)];
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

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
void solve(int t) {
	reset();
	cout << "Case " << t << ":" << endl;

	int n, q; cin >> n >> q;
	n -= 1;
	while (q--) {
		int cmnd; cin >> cmnd;
		if (cmnd == 1) {
			int l, r, newVal;
			cin >> l >> r >> newVal;
			update(0, 0, n, l, r, newVal);
		}
		else {
			int l, r;
			cin >> l >> r;
			int diff = r - l + 1;
			int ans = query(0, 0, n, l, r);
			int cPrime = gcd(ans, diff);
			if (ans%diff == 0)cout << (ans / diff) << endl;
			else {
				ans /= cPrime;
				diff /= cPrime;
				cout << ans << "/" << diff << endl;
			}
		}
	}

}
int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}
}

/*
i/o by yakin.rubaiat16	(udebug)

i/p:

11
39 5
1 8 26 0
1 18 22 83
1 5 21 54
1 8 26 74
2 12 35
22 5
1 2 7 0
1 4 18 13
1 9 17 9
1 7 12 67
2 0 21
60 6
1 29 39 50
1 7 21 13
1 0 17 58
1 2 29 39
1 6 50 28
2 0 59
50 5
1 0 48 94
1 15 36 14
1 14 26 73
2 27 38
2 0 49
23 3
1 1 18 49
1 11 22 0
2 17 17
29 5
1 5 6 95
1 2 23 0
1 1 5 69
1 22 23 42
2 0 28
37 6
1 0 12 78
1 9 31 79
1 8 30 0
1 14 16 28
2 12 17
2 0 36
19 2
1 2 10 69
2 10 15
28 2
1 2 4 42
2 0 27
28 4
1 16 18 608
1 19 20 11
1 5 10 632
2 9 23
8 5
1 0 7 5
1 2 5 10
2 0 7
2 1 5
2 4 6



o/p:

Case 1:
185/4
Case 2:
499/22
Case 3:
383/15
Case 4:
82/3
3533/50
Case 5:
0
Case 6:
429/29
Case 7:
14
787/37
Case 8:
23/2
Case 9:
9/2
Case 10:
622/3
Case 11:
15/2
9
25/3

*/
