class Solution {
public:
    int dp[1000];
    int go(int n){
        if(n<=0)return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = go(n-1) + go(n-2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof dp);
        int ans = go(n);
        return ans;
    }
};
