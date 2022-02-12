class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1, INT_MAX);
        //base case
        dp[0] = 0;
        int ps = 1; // perfect square limit
        while(ps * ps <= n){
            int sq = ps*ps;
            // checking all combinations
            for(int i = sq; i<=n; i++){
                dp[i] = min(dp[i-sq]+1, dp[i]);
            }
            ps++; // updating
        }
        return dp[n];
    }
};
