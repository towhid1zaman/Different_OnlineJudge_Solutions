class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = (int)nums.size();
        map<int, int>seen;
        int pSum = 0;
        seen[0] = 1;
        int ans = 0;
        for(int i = 0; i<n; i++){
            pSum += nums[i];
            int rem = pSum%k;
            if(rem < 0)rem+=k;
            ans += seen[rem];
            seen[rem]++;
        }
        return ans;
    }
};
