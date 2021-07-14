class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int mex = 1;
        for(int i = 0; i<n; i++){
            if(nums[i] == mex)mex++;
        }
        return mex;
    }
};
