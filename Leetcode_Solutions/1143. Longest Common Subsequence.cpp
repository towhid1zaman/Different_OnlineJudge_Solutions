class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        
        int n = (int)s.size(), m = (int)t.size();
        int dp[3001][3001];
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1]==t[j-1])dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
