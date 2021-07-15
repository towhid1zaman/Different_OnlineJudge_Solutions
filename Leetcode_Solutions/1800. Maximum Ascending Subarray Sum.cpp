class Solution {
public:
    int maxAscendingSum(vector<int>& a) {
        int ans = 0, cnt = 0;
        int n = (int)a.size();
        if(n==1)return a[0];
        for(int i = 0;i<n; i++){
            cnt+=a[i];
            if(i==n-1)ans = max(ans, cnt);
            else if((a[i+1] <= a[i]) and i+1 < n){
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};
