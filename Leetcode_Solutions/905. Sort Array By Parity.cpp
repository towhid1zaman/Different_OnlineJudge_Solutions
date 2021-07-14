class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        vector<int>ans;
        int n = (int)a.size();
        for(int i = 0; i<n; i++){
            if(a[i]%2==0)ans.push_back(a[i]);
        }
        for(int i = 0; i<n; i++){
            if(a[i]%2)ans.push_back(a[i]);
        }
        return ans;
    }
};
