class Solution {
public:
    int n, w;
    int a[333];
    int dp[333][5005];

    int go(int pos, int weight){
        if(pos >= n){
            if(weight == 0)return 1;
            else return 0;
        }

        if(dp[pos][weight]!=-1)return dp[pos][weight];

        int take = 0, dont_take = 0;
        if(weight - a[pos] >= 0) take = go(pos, weight - a[pos]);
        dont_take = go(pos+1, weight);
        return dp[pos][weight] = take + dont_take;

    }
    int change(int amount, vector<int>& coins) {
        n = (int)coins.size();
        for(int i = 0; i<(int)coins.size(); i++){
            a[i] = coins[i];
        }
        memset(dp, -1, sizeof(dp));
        return go(0, amount);
    }
};
