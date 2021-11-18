class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int diff_bit = 0;
        while(left != right){
            left >>=1;
            right >>=1;
            diff_bit++;
        }
        int ans = left << diff_bit;
        return ans;
    }
};
