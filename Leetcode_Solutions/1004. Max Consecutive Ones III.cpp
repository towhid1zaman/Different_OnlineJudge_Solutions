class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int i = 0, j = 0, n = a.size(), ans = INT_MIN, zero = 0;
        while(j < n){
            if(zero < k){
                if(a[j]==1){}
                else zero++;
                j++;
            }
            else if(zero == k){
                if(a[j]==1)j++;
                else if(a[i]==1)i++;
                else if(a[i]==0){
                    zero--;
                    i++;
                }
                ans = max(ans, (j-i));
            }
        }
        ans = max(ans, (j-i));
        return ans;
    }
};
