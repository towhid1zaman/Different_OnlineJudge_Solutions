class Solution {
public:
    int func(int i,int s,int e,vector<int>& nums,vector<int>& multipliers,vector<vector<int>>& dp)
    {
        if(i >= multipliers.size())  
            return 0;  
        if(dp[s][i] != -1001)
            return dp[s][i];

        int t1 = func(i+1,s+1,e,nums,multipliers,dp) + nums[s]*multipliers[i];
        int t2 = func(i+1,s,e-1,nums,multipliers,dp) + nums[e]*multipliers[i];
        
        return dp[s][i] = max(t1,t2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
      vector<vector<int>> dp(1000,vector<int>(1000,-1001));    
      int s=0;
      int e=nums.size()-1;  
      return func(0,s,e,nums,multipliers,dp); 
    }
};
