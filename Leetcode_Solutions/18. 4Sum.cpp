class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector< vector<int> > ans;
        int n = (int)a.size();
        set<vector<int>>s;
        sort(a.begin(), a.end());
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n-2; j++){
                int new_target = target -  (a[i] + a[j]);
                int l = j+1, r = n-1;
                while(l < r){
                    int sum = a[l] + a[r];
                    if(sum < new_target)l++;
                    else if(sum > new_target)r--;
                    else{
                        s.emplace(vector<int>{a[i], a[j], a[l], a[r]});
                        l++, r--;
                    }
                }
            }
        }
        for(auto i:s)ans.push_back(i);
        return ans;
    }
};
