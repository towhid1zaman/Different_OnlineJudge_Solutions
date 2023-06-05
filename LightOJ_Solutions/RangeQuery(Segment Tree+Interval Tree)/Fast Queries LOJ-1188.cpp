#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

int nums[MAXN];
int tree[4*MAXN];


int left(int node){return node*2+1;}
int right(int node){return node*2+2;}
int half(int left,int right){return left+(right-left)/2;}

void build(int node, int b, int e){
    if(b > e)return;
    if(b==e){
        tree[node] = 0;
        return;
    }
    int mid = half(b, e);
    build(left(node), b, mid);
    build(right(node), mid + 1, e);
    tree[node] = tree[left(node)] + tree[right(node)];
}

void updatePoint(int node, int b, int e, int pos, int newVal){
    if(b == e){
        tree[node] += newVal;
        return;
    }
    int mid = half(b, e);
    if(pos <= mid){
        updatePoint(left(node), b, mid, pos, newVal);
    }
    else{
        updatePoint(right(node), mid + 1, e, pos, newVal);
    }
    tree[node] = tree[left(node)] + tree[right(node)];
}

int query(int node, int b, int e, int l, int r){
    if(e < l || b > r)return 0;
    if(b >= l && e <= r){
        return tree[node];
    }

    int mid = half(b, e);
    return query(left(node), b, mid, l, r) + query(right(node), mid + 1, e, l, r);
}

void solve(int t){
    cout << "Case "<<t<<":"<<endl;
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    build(0, 0, n-1);
    vector<pair<int, int>>markQ[n];
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l--, r--;
        markQ[r].push_back({l, i});
    }
    int ans[q];
    unordered_map<int, int>lastPos;
    for(int r = 0; r < n; r++){
        if(lastPos.find(nums[r]) != lastPos.end()){
            int previousPosition = lastPos[nums[r]];
            updatePoint(0, 0, n-1,previousPosition, -1);
        }
        updatePoint(0, 0, n-1, r, 1);
        lastPos[nums[r]] = r;
        for(auto [l, index] : markQ[r]){
            ans[index] = query(0, 0, n-1, l, r);
        }
    }
    for(int i = 0; i < q; i++){
        cout << ans[i]<<endl;
    }
}

int main(){
   int T; cin >> T;
   for(int t = 1; t <= T; t++){
    solve(t);
   }
}
