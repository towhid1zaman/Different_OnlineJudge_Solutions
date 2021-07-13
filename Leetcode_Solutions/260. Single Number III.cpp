class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int>m;
        for(int i = 0; i< (int)nums.size(); i++){
            m[ nums[i] ]++;
        }
        vector<int>ans;
        for(auto x: m){
            if(x.second == 1)ans.push_back(x.first);
        }
        return ans;        
    }
};
