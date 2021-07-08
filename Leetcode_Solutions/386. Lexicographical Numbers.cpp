class Solution {
public:
    vector<int>ans;
    void go(int n, int i){
        if(i > n)return;
        if(i>0)ans.push_back(i);
        for(int j = (i==0?1:0); j<=9; j++){
            go(n, 10*i+j);
        }
    }
    vector<int> lexicalOrder(int n) {
        go(n, 0);
        return ans;
    }
};
