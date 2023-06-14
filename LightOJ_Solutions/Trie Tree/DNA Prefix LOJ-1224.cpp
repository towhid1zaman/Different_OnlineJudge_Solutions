#include<bits/stdc++.h>
using namespace std;

int getIndex(char c){
    if(c == 'A')return 0;
    else if(c == 'C')return 1;
    else if(c == 'G')return 2;
    else if(c == 'T')return 3;
}

struct node{
    int cnt;
    node *child[4];
    node(){
        cnt = 0;
        for(int i = 0; i < 4; i++){
            child[i] = nullptr;
        }
    }
}*root;

void insert(string s){
    node *cur = root;
    cur->cnt = 0;
    for(char c:s){
        int index = getIndex(c);
        if(cur->child[index] == nullptr){
            cur->child[index] = new node();
        }
        cur = cur->child[index];
        cur->cnt++;
    }
}

void delNode(node *cur){
    for(int i = 0; i < 4; i++){
        if(cur->child[i] != nullptr){
            delNode(cur->child[i]);
        }
    }
    delete(cur);
}

int dfs(node *cur, int level){
    int ret = cur->cnt*level;
    for(int i = 0; i < 4; i++){
        if(cur->child[i] != nullptr){
            ret = max(ret, dfs(cur->child[i], level + 1));
        }
    }
    return ret;
}

void solve(int t){
    int q; cin >> q;
    root = new node();
    string s;
    for(int i = 0; i < q; i++){
        cin >> s;
        insert(s);
    }
    cout << "Case "<<t<<": ";
    int ans = dfs(root, 0);
    cout << ans << endl;
    delNode(root);
}

int main(){
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
    return 0;
}
