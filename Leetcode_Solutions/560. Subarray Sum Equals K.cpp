class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int pSum = 0;
        map<int, int>seen; // how many times already we seen the value current Psum - k
        int ans = 0;
        seen[0] = 1;
        for(int i = 0; i<n; i++){
            pSum += nums[i];
            ans+=seen[pSum - k];
            seen[ pSum ] += 1;
        }
        return ans;
    }
};
