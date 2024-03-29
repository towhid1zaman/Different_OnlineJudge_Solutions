class Solution {
public:
    vector<int>original;
    int n;
    Solution(vector<int>& nums) {
        original = nums;
        n = (int)nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>shuffled = original;;
        int left = n;
        for(int i = n-1; i>=0; i--){
            int j = rand()%left;
            swap(shuffled[i], shuffled[j]);
            left--;
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
