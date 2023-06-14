#include<bits/stdc++.h>
using namespace std;

inline int getIndex(char c){
    return c - '0';
}

struct node{
    int isLeaf;
    node *child[26];
    node(){
        isLeaf = 0;
        for(int i = 0; i < 10; i++){
            child[i] = nullptr;
        }
    }
}*root;

bool insert(string s){
    node *cur = root;
    int isPrefix = 1;
    for(char c:s){
        int index = getIndex(c);
        if(cur->child[index] == nullptr){
            cur->child[index] = new node();
            isPrefix = 0;
        }
        cur = cur->child[index];
        if(cur->isLeaf > 0){
            return 1;
        }
    }
    cur->isLeaf++;
    return isPrefix;
}

void delNode(node *cur){
    for(int i = 0; i < 10; i++){
        if(cur->child[i] != nullptr){
            delNode(cur->child[i]);
        }
    }
    delete(cur);
}

void solve(int t){
    int q; cin >> q;
    root = new node();
    string s[q+1];
    for(int i = 0; i < q; i++){
        cin >> s[i];
    }
    cout << "Case "<<t<<": ";
    int ans = 0;
    for(int i = 0; i < q; i++){
        ans = insert(s[i]);
        if(ans == 1){
            break;
        }
    }
    if(ans)cout << "NO"<<endl;
    else cout << "YES"<<endl;
    delNode(root);
}

int main(){
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
    return 0;
}
