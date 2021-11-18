class Solution {
public:
    void subset(int p, vector<int>& nums, vector<int>&a, int &res){
        if(p == nums.size()){
            int Xor = 0;
            for(int x:a)Xor^=x;
            res+=Xor;
            return;
        }
        //take;
        a.push_back(nums[p]);
        subset(p+1, nums, a, res);
        //dont take;
        a.pop_back();
        subset(p+1, nums, a, res);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int>a;
        int ans = 0;
        subset(0,nums, a, ans);
        return ans;
    }
};
