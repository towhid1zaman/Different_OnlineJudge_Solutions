class Solution {
public:
    int search(vector<int>& a, int target) {
        int low = 0, high = a.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(a[mid] == target){
                return mid;
            }
            if(a[mid] > a[high]){
                // exist in left side
                if(target < a[mid] and target >= a[low]){
                    high = mid -1;
                }
                else low = mid+1;
            }
            else if(a[mid] < a[low]){
                //exist in right side
                if(target > a[mid] and target <= a[high]){
                    low = mid+1;
                }
                else high = mid-1;
            }
            else{
                if(target < a[mid]){
                    high = mid-1;
                }
                else low = mid+1;
            }
        }
        return -1;
    }
};
