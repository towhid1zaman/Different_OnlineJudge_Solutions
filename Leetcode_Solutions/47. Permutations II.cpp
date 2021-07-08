class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
                vector<vector<int>> per;
        sort(nums.begin(), nums.end());
        do{
            per.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return per;
    }
};
