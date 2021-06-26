class Solution {
public:
    int dp[111][111];
    int go(int i, int j){
        if(i==1 or j==1)return 1;
        if(i==2 and j==2)return 2;
        if(dp[i][j] != -1)return dp[i][j];
        return dp[i][j] = go(i-1, j) + go(i, j-1);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof (dp));
        int ans = go(m, n);
        return ans;
    }
};
