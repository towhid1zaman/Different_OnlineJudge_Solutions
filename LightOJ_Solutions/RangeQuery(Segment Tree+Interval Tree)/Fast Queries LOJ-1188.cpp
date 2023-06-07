#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXN 100005

int nums[MAXN];
int tree[4*MAXN];
int last[MAXN];

struct OfflineData {
	int index, l, r, ans;
};

void reset() {
	memset(nums, 0, sizeof nums);
	memset(tree, 0, sizeof tree);
	memset(last , -1, sizeof last);
}

int left(int node) { return 2 * node + 1; }
int right(int node) { return 2 * node + 2; }
int half(int left, int right) { return left + (right - left)/2; }

void build(int node, int b, int e) {
	if (b > e)return;
	if (b == e) {
		tree[node] = 0;
		return;
	}
	int mid = half(b, e);
	build(left(node), b, mid);
	build(right(node), mid + 1, e);
	tree[node] = tree[left(node)] + tree[right(node)];
}

void updatePoint(int node, int b, int e, int pos, int newVal) {
	if (b == e){
		tree[node] = newVal;
		return;
	}
	int mid = half(b, e);
	if (pos <= mid) {
		updatePoint(left(node), b, mid, pos, newVal);
	}
	else {
		updatePoint(right(node), mid + 1, e, pos, newVal);
	}
	tree[node] = tree[left(node)] + tree[right(node)];
}

int query(int node, int b, int e, int l, int r) {
	if (e < l || b > r)return 0;
	if (b >= l && e <= r) {
		return tree[node];
	}
	int mid = half(b, e);
	return query(left(node), b, mid, l, r) + query(right(node), mid + 1, e, l, r);
}

bool compRightVal(OfflineData a, OfflineData b) {
	return a.r < b.r;
}

bool compIndex(OfflineData a, OfflineData b) {
	return a.index < b.index;
}

void solve(int t) {

	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	//build(0, 0, n - 1);

	vector<OfflineData>QueryData;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r; l--, r--;
		OfflineData temp;
		temp.index = i, temp.l = l, temp.r = r;
		QueryData.push_back(temp);
	}
	sort(QueryData.begin(), QueryData.end(), compRightVal);
	
	int qdInd = 0;
	for (int i = 0; i < n; i++) {
		int curVal = nums[i];

		if (last[curVal] != -1) {
			updatePoint(0, 0, n - 1, last[curVal], -1);
		}

		updatePoint(0, 0, n - 1, i, 1);
		last[curVal] = i;
		
	
		while (QueryData[qdInd].r == i){
			QueryData[qdInd].ans = query(0, 0, n - 1, QueryData[qdInd].l, QueryData[qdInd].r);
			qdInd++;
		}
	}
	sort(QueryData.begin(), QueryData.end(), compIndex);

	cout << "Case " << t << ":" << endl;
	for (auto i:QueryData) {
		cout << i.ans << endl;
	}
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		reset();
		solve(t);
	}
}
