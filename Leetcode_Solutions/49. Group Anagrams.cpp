class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = (int)strs.size();
        map<string, vector<string> >mp;
        vector< vector<string> >ans;
        for(int i = 0; i<n; i++){
            string s = strs[i];
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        for(auto x:mp){
            vector<string>cur;
            for(auto c:x.second){
                cur.push_back(c);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
