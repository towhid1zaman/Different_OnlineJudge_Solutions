class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        int p = 1;
        vector<int>Po;
        int z = 0;
        for(int i : nums){
            if(!i)z++;
            if(i)p*=i;
        }
        if(z>1){
            Po.resize(n, 0);
            return Po;
        }
        for(int i:nums){
            if(z){
                if(!i)Po.push_back(p);
                else Po.push_back(0);
            }
            else Po.push_back(p/i);
        }
        return Po;
    }
};
