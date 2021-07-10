class Solution {
public:
    void print(vector<char>&s, int l, int r){
        if(l>=r)return;
        swap(s[l], s[r]);
        print(s, l+1, r-1);
    }
    void reverseString(vector<char>& s) {
        int n = (int)s.size();
        print(s, 0, n-1);
    }
};
