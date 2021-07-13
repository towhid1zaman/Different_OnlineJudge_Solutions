class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        map<int, int>m;
        for(int i = 0; i<(int)nums.size(); i++){
            if(m[nums[i]])ans=nums[i];
            m[nums[i]]++;
        }
        return ans;
    }
};
