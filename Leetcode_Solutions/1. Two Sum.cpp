class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        map<int, int>mp;
        vector<int>ans;
        for(int i = 0; i<n; i++){
            int need = target - nums[i];
            if(mp.find(need) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[need]);
                break;
            }
            else{
                mp[nums[i]] = i;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
