class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>a;
        int n = (int)nums.size();
        map<int, int>m;
        for(int i = 1; i<=n; i++){
            m[ nums[i-1] ]++;
        }

        for(int i = 1;i<=n; i++){
            if(!m[i])a.push_back(i);
        }
        return a;
    }
};
