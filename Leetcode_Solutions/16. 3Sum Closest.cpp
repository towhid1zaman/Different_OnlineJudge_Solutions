class Solution {
public:
  
    int threeSumClosest(vector<int>& a, int target) {
        int n = (int)a.size();
        int mn = INT_MAX, ans;
        sort(a.begin(), a.end());
        for(int i = 0; i<n-1; i++){
            int l = i+1, r = n-1;
            while(l < r){
                int sum = a[i] + a[l] + a[r];
                int dif = abs(target - sum);
                
                if(dif < mn){
                    mn = dif;
                    ans = sum;
                }
                if(sum < target) l++;
                else if(sum > target)r--;
                else{
                    ans = sum;
                    i = n-2; // break outer loop
                    break; // break current loop
                }
            }
        }
        return ans;
    }
  
};
