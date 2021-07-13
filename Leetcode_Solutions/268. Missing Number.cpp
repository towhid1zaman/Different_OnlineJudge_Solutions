class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = (int)nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] != i)return i;
        }
        return n;
    }
};
