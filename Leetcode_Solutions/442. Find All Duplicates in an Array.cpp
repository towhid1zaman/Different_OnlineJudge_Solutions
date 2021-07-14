class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        map<int, int>m;
        int n = (int)a.size();
        for(int i = 0; i<n; i++){
            m[ a[i] ]++;
        }
        vector<int>ans;
        for(auto x:m){
            if(x.second>1)ans.push_back(x.first);
        }
        return ans;
    }
};
