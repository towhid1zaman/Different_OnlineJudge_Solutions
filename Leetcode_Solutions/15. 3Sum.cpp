class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = (int)a.size();
        int mn = INT_MAX;
        vector< vector<int> >ans;
        sort(a.begin(), a.end());
        for(int i = 0; i<n-1; i++){
            if(i > 0 and a[i]==a[i-1])continue; // avoid duplicates
            int l = i+1, r = n-1;
            while(l < r){
                int sum = a[i] + a[l] + a[r];
                if(sum < 0) l++;
                else if(sum > 0)r--;
                else{
                    ans.push_back(vector<int>{a[i], a[l], a[r]});
                    while(l+1 < r and a[l+1]==a[l])l++; // avoid duplicates
                    while(r-1 > l and a[r-1]==a[r])r--; // avoid duplicates
                    l++, r--;
                }
            }
        }
        return ans;        
    }
};
