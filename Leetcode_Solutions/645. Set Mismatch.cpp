class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> id;
        int n = (int)nums.size();
        map<int, int>m, M;
        for(int i = 1;i<=n; i++){
            m[nums[i-1]]++;
        }
        
        for(int i = 0; i<n; i++){
            if(m[nums[i]]>1 and M[nums[i]] == 0){
                id.push_back(nums[i]);
                M[ nums[i] ]++;
            }
        }
        for(int i = 1; i<=n; i++)if(m[i]==0)id.push_back(i);
        return id;
    }
};
