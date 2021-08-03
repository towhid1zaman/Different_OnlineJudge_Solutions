class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = (nums.size());
        vector<int>ans;
        int id1 = lower_bound(nums.begin(),nums.end(), target) - nums.begin();
        int id2 = (upper_bound(nums.begin(),nums.end(), target) - nums.begin()) - 1;
        ans.push_back(id1);
        ans.push_back(id2);
        if(ans.empty() or id1 > id2){
            ans.clear();
            ans.push_back(-1);ans.push_back(-1);
        }
        return ans;
    }
};
