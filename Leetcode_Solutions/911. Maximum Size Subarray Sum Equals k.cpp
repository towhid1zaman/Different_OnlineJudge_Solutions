class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        int n = (int)nums.size();
        int pSum = 0;
        map<int, int>seen;
        int ans = 0;
        seen[0] = -1;
        for(int i = 0; i<n; i++){
            pSum += nums[i];
            if(seen.find(pSum - k) != seen.end()){
                ans = max(ans, i- seen[pSum - k]);
            }
            if(seen.find(pSum) == seen.end()){
                seen[pSum] = i;
            }
        }
        return ans;
    }
};
