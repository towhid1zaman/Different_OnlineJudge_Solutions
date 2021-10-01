
class Solution {
public:
    int thirdMax(vector<int>& nums) {
    long long one = LONG_MIN, two = LONG_MIN, three = LONG_MIN;
    for(int x:nums){
       if(x == one || x == two || x ==three)continue;
        if(x > one){
            three = two;
            two = one;
            one = x;
        }
        else if(x > two){
            three = two;
            two = x;
        }
        else if(x > three){
            three = x;
        }
    }
    return three == LONG_MIN ? one : three;
}
};
