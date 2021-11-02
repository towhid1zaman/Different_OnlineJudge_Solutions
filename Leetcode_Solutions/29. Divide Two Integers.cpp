class Solution {
public:
int divide(int dividend, int divisor) {
    if(dividend == INT_MIN and divisor == -1){
        return INT_MAX;
    }
    long long dvd = abs(dividend), divi = abs(divisor);
    long long ans = 0;
    while(dvd >= divi){
        long long cur = divi, cur_count = 1;
        while( (cur <<1) <= dvd){
            cur<<=1;
            cur_count<<=1;
        }
        ans+=cur_count;
        dvd-=cur;
    }
    if(dividend<0 and divisor<0)return ans;
    else if((dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0))return ans*-1ll;
    else return ans;
}
};
