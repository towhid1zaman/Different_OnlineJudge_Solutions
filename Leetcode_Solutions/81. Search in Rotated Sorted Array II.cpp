class Solution {
public:
    bool search(vector<int>& a, int target) {
        int low = 0, high = a.size()-1;
        while(low <= high){
            while (low < high and a[low] == a[low + 1]) {
                low++;
            }
            while (low < high and a[high] == a[high - 1]) {
                high--;
            }
            int mid = (low+high)/2;
            if(a[mid] == target){
                return 1;
            }
            if(a[mid] > a[high]){
                // exist in left side
                if(target < a[mid] and target >= a[low]){
                    high = mid-1;
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
        return 0;        
    }
};
