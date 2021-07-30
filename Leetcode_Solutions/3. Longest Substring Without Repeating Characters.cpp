class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size();
        map<char, int>mp;
        int ans = 0;
        int l = 0, r = 0;
        while(r < n){
            if(mp.find(s[r]) != mp.end() and mp[s[r]] >= l){
                l = mp[s[r]] + 1;
            }
            ans = max(ans, r - l + 1);
            mp[s[r++]] = r;
        }
        return ans;
    }
};
