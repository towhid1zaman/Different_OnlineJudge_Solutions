class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>m;
        for(auto x:nums)m[x]++;
        vector< pair<int, int> >v;
        for(auto x:m){
            v.emplace_back(x.second, x.first);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector<int>ans;
        for(int i = 0;i < k; i++)ans.push_back(v[i].second);
        return ans;
    }
};
