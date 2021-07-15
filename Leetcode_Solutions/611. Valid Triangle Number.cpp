class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int n = (int)a.size();
        int ans = 0;
        sort(a.begin(), a.end());
        for(int i = n-1; i>=0; i--){
            int lo = 0, hi = i-1;
            while(lo < hi){
                if(a[i] < a[lo]+a[hi]){
                    ans+=(hi-lo);
                    hi--;
                }
                else lo++;
            }
        }
        return ans;
    }
};
