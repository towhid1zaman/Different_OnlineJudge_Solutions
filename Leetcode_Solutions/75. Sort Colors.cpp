class Solution {
public:
    void sortColors(vector<int>& nums) {
        int startPos = 0, endPos = (int)nums.size() - 1, curPos = 0;
        
        while(curPos <= endPos){
            if(nums[curPos] == 0){
                swap(nums[curPos++], nums[startPos++]);
            }
            else if(nums[curPos] == 1){
                curPos++;
            }
            else if(nums[curPos] == 2){
                swap(nums[curPos], nums[endPos--]);
            }
        }
    }
};
