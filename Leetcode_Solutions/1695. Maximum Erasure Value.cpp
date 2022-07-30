class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxAns = 0, startPos = 0, sum = 0;
        bool mark[11111]={};
        for(int endPos = 0; endPos < (int)nums.size(); endPos++){
            while(mark[ nums[endPos] ]){
                sum -= nums[startPos];
                mark[ nums[startPos] ] = 0;
                startPos++;
            }
            
            sum += nums[endPos];
            maxAns = max(maxAns, sum);
            mark[ nums[endPos] ] = 1;
            
        }
        
        return maxAns;
    }
};
