class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = (int)s.size();
        string ans;
        int g = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i] == '-')continue;
            ans.push_back(toupper(s[i]));
            g++;
            if(g==k){
                ans.push_back('-');
                g = 0;
            }
        }
        if(ans.back() == '-')ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
