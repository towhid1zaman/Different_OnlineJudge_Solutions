class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int startPos = 0, endPos = (int)nums.size() - 1, curPos = endPos;
        vector<int>ans((int)nums.size(), 0);
        while(curPos >= 0){
            if( abs(nums[startPos])  > abs(nums[endPos]) ){
                ans[curPos--] = nums[startPos] * nums[startPos++];
            }
            else{
                ans[curPos--] = nums[endPos] * nums[endPos--];
            }
        }
        return ans;
    }
};
