class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        map<int, int>m;
        for(int i = 0; i< (int)nums.size(); i++){
            m[ nums[i] ]++;
        }
        for(auto x: m){
            if(x.second == 1)ans = x.first;
        }
        return ans;
    }
};
