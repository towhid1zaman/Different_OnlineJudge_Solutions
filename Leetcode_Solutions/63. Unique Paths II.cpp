class Solution {
public:
    int dp[1111][1111];
    int go(int n, int m){
        if(dp[n][m] != -1)return dp[n][m];
        if(n<1 and m<1)return 0;
        if(n==1 and m==1)return 1;
        int a = go(n-1, m);
        int b = go(n, m-1);
        if(a < 0)a = 0;
        if(b < 0)b = 0;
        return dp[n][m] = (a+b);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(obstacleGrid[i][j]==1)dp[i+1][j+1] = -1000000007;
                else dp[i+1][j+1] = -1;
            }
        }
        if(dp[0][0] == -1000000007 or dp[n][m] == -1000000007)return 0;
        
        int ans = go(n, m);
        return ans;
    }
};
