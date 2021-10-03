class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = (int)nums.size();
        double ans = 0, sum = 0, res = INT_MIN;
        for(int i = 0; i<n; i++){
            if(i < k)sum+=nums[i];
            else{
                res = max(res, sum);
                sum += nums[i] - nums[i-k];
            }
        }
        res = max(res, sum);
        return res/k;
    }
};
