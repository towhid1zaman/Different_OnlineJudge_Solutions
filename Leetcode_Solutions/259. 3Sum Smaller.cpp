class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &a, int target) {
        int n = (int)a.size();
        int ans = 0;
        sort(a.begin(), a.end());
        for(int i = 0; i<n-1; i++){
            int l = i+1, r = n-1;
            while(l < r){
                int sum = a[i] + a[l] + a[r];
                if(sum >= target)r--;
                else ans+=(r-l),l++;
            }
        }
        return ans;       
    }
};
