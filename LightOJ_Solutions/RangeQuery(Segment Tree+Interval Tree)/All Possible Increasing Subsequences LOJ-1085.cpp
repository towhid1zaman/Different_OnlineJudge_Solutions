#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define int long long
#define MAXN 100005

int nums[MAXN];
int tree[4*MAXN];

int left(int node){return 2*node + 1;}
int right(int node){return 2*node + 2;}
int half(int left, int right){return left + (right - left)/2;}

void reset(){
    memset(nums, 0, sizeof nums);
    memset(tree, 0, sizeof tree);
}

void build(int node, int b, int e){
    if(b > e)return;

    if(b == e){
        tree[node] = nums[b];
    }
    int mid = half(b, e);
    build(left(node), b, mid);
    build(right(node), mid + 1, e);
    tree[node] = tree[left(node)] + tree[right(node)];
}


void update(int node, int b, int e, int pos, int newVal){
    if(b == e){
        tree[node] = (tree[node] + newVal)%1000000007;
        return;
    }
    int mid = half(b, e);
    if(pos <= mid){
        update(left(node), b, mid, pos, newVal);
    }
    else{
        update(right(node), mid + 1, e, pos, newVal);
    }
    tree[node] = tree[left(node)] + tree[right(node)];
}


int query(int node, int b, int e, int l, int r){

    if(e < l || b > r)return 0;
    if(b >= l && e <= r){
        return tree[node];
    }
    int mid = half(b,e);
    int x = query(left(node), b, mid, l, r);
    int y = query(right(node), mid + 1, e, l, r);

    return (x + y)%1000000007;
}
bool comp(pair<int, int>&a, pair<int, int>&b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    else return a.first < b.first;
}
void solve(int t) {
	int n; cin >> n;
    vector<pair<int, int>>v;
	for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.emplace_back(num, i);
	}
	sort(v.begin(), v.end(), comp);

    int ans = 0;
    for(int i = 0; i < n; i++){
        int pos = v[i].second;
        int k = 1 + query(0, 0, n-1, 0, pos);
        update(0, 0, n-1, pos, k);
        ans = (ans + k)%1000000007;
    }
	cout << "Case " << t << ": " << ans << endl;
}

 main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		reset();
		solve(t);
	}
}
