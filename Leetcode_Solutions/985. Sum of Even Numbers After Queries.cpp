class Solution {
public:

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int evenSum = 0;
        for(auto &num:nums){
            if(num%2==0)evenSum += num;
        }

        vector<int>ans;
        for(int i = 0; i<queries.size(); i++){
            vector<int>cur = queries[i];
            int curVal = cur[0];
            int curIndex = cur[1];
            int preVal = nums[curIndex];

            if(abs(curVal + preVal)%2 == 0){
                if(abs(preVal) % 2 == 1)evenSum += (curVal + preVal);
                else evenSum += curVal;
                
                nums[curIndex] += curVal; 
            }else{
                if(abs(preVal)%2==0)evenSum -= preVal;
                nums[curIndex] += curVal; 
            }
            ans.push_back(evenSum);
            
        }
        return ans;
    }
};
