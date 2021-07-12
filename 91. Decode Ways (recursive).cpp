class Solution {
public:
    
    vector<int>dp;
    int go(int p, string s, int n){
        if(p==n){
            return dp[p] = 1;
        }
        if(dp[p]!=-1)return dp[p];
        if(s[p] == '0')return dp[p] = 0;
        int res = go(p+1, s, n);
        if(p < n-1 and (s[p]=='1' or s[p]== '2' and s[p+1] <= '6') )res += go(p+2, s, n);
        return dp[p] = res;
    }
    
    int numDecodings(string s) {
        int n = (int)s.size();
        dp.assign(n+1, -1);    
        if(n==0)return 0;
        return go(0,s, n);
    }
    
};
