class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)(prices.size());
        std::vector<int>Mx(n+1, -1);
        for(int i = n-1; i>=0; i--)Mx[i] = max(Mx[i+1], prices[i]);
        int ans = -1;
        for(int i = 0; i<n; i++){
            cout << Mx[i]<<' ';
            if(i+1<n)ans = max((Mx[i+1] - prices[i]), ans);
        }
        if(ans < 0)return 0;
        else return ans;
    }
};
