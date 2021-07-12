class Solution {
public:
    
    vector<int>dp;
    int numDecodings(string s) {
        int n = (int)s.size();
        dp.assign(n+1, 0);    
        if(n==0)return 0;
        
        dp[0] = 1;
        if(s[0]!='0')dp[1] = 1;
        for(int i = 2; i<=n; i++){
            int a = s[i-1]-'0';
            int b = a + (s[i-2]-'0')*10;
            if(a >= 1)dp[i] += dp[i-1];
            if(b <=26 and b >= 10) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
    
};
