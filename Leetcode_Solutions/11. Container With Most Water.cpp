class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = (int)h.size();
        int left = 0, right = n-1;
        long long  ans = 0;
        while(left < right){
            int w = right - left;
            ans = max(ans, (long long) w*min(h[right], h[left]));
            if(h[left] < h[right])left++;
            else right--;
        }
        return ans;
    }
};
