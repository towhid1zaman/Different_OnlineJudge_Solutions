/*
0 ^ (0/2) = 0 = 0000
1 ^ (1/2) = 1 ^ 0 = 1 = 0001
2 ^ (2/2) = 2 ^ 1 = 3 = 0011
3 ^ (3/2) = 3 ^ 1 = 2 = 0010
*/
class Solution {
public:
    vector<int> grayCode(int n) {

        vector<int>ans;
        for(int i = 0; i<(1<<n); i++){
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};
