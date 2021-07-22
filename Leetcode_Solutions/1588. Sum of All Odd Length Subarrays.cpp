class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = (int)arr.size();
        for(int i = 0; i<n; i++){
            int occurences = ((i + 1) * (n - i));
            ans += (arr[i] * (  (occurences + 1)/ 2 ) );// taking ceil
        } 
        return ans;
    }
};
