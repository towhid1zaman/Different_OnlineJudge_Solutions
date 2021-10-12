class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int l = 0, r = (int)a.size()-1;
        vector<int>ans;
        while(l < r){
            if(a[l]+a[r] == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
            else if(a[l] + a[r] > target)r--;
            else l++;
        }
        return ans;
    }
};
