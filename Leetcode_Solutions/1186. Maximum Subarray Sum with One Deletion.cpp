class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans = INT_MIN;
        int n = (int)arr.size();
        vector<int>L(n+1, 0), R(n+1, 0);
        L[0] = arr[0];
        for(int i = 1; i<n; i++){
            L[i] = max(L[i-1] + arr[i], arr[i]);
            ans = max(ans, L[i]);
        }
        R[n-1] = arr[n-1];
        ans = arr[n-1];
        for(int i = n-2; i>=0; i--){
            R[i] = max(R[i+1]+arr[i], arr[i]);
            ans = max(ans, R[i]);
        }
        for(int i = 1; i+1 < n; i++){
                ans = max(ans, L[i-1] + R[i+1]);
        }
        return ans;
    }
};
