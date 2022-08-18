class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int)nums.size();
        int startPos = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] != val){
                nums[startPos++] = nums[i];
            }
        }
        return startPos;
    }
};
