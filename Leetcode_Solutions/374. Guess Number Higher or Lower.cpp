/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1, r = n;
        int ans;
        while(l <= r){
            long long mid = (l+r+1)/2ll;
            if(!guess(mid)){
                ans = mid;
                break;
            }
            else if(guess(mid) == -1)r = mid-1;
            else l = mid+1;
        }
        return ans;
    }
};
