class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if(n < 3)return 0;
        vector<int>maxl(n, 0), maxr(n, 0);
        long long ans = 0;
        maxl[0] = 0;
        for(int i = 1; i<n; i++){
            maxl[i] = max(maxl[i-1], height[i-1]);
        }
        maxr[n-1] = 0;
        for(int i = n-2; i>=0; i--){
            maxr[i] = max(maxr[i+1], height[i+1]);
        }
        for(int i = 0; i<n; i++){
            long long cur = ( min(maxl[i], maxr[i]) - height[i]);
            if(cur > 0)ans += cur;
        }
        return ans;
    }
};
