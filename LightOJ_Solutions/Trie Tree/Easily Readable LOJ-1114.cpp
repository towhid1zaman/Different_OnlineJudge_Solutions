#include<bits/stdc++.h>
using namespace std;

inline int getIndex(char c) {
	if(c >= 'a' & c <='z')return c - 'a';
	return c - 'A' + 26;
}

struct trie {
	int leaf = 0;
	trie* child[52];
	trie() {
		leaf = 0;
		for (int i = 0; i < 52; i++) {
			child[i] = NULL;
		}
	}
}* root;

void insert(string &s) {
	if(s.size() > 2)sort(s.begin() + 1, s.end() - 1);
	trie* cur = root;
	for (char c : s) {
		int index = getIndex(c);
		if (cur->child[index] == NULL) {
			cur->child[index] = new trie();
		}
		cur = cur->child[index];
	}
	cur->leaf += 1;
}

int search(string &s) {
	if (s.size() > 2)sort(s.begin() + 1, s.end() - 1);
	trie* cur = root;
	for (char c : s) {
		int index = getIndex(c);
		if (cur->child[index] == NULL)return 0;
		cur = cur->child[index];
	}
	return cur->leaf;
}

void del(trie* node) {
	node->leaf = 0;
	for (int i = 0; i < 52; i++) {
		if (node->child[i] != NULL)del(node->child[i]);
	}
	delete(node);
}

void solve(int t) {
	int n; cin >> n;
	string s;
	root = new trie();
	for (int i = 0; i < n; i++) {
		cin >> s;
		insert(s);
	}
	cin >> n;
    cin.ignore();
    cout << "Case " << t << ":" << endl;
    while(n--){
        int ans = 1;
        getline(cin,s);
        stringstream ss(s);
        while(ss >> s) ans *= search(s);
        cout << ans << endl;
    }
	del(root);
}
int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}
}
