class Solution {
public:
    int LIS(vector<int>v, int n){
    vector<int>temp;
    temp.push_back(v[0]);
    for(int i = 1; i<n; i++){
        if(v[i]>temp.back()){
            temp.push_back(v[i]);
        }
        else{
            auto it = lower_bound(temp.begin(),temp.end(),v[i]) - temp.begin();
            temp[it] = v[i];
        }
    }

    return temp.size();
}
    
    int lengthOfLIS(vector<int>& nums) {
        int ans = LIS(nums, (int)nums.size());
        return ans;
    }
};
