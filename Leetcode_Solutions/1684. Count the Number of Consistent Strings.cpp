class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, int>mp;
        for(char c:allowed){
            mp[c] = 1;
        }
        int ans = 0;
        for(string s:words){
            int x = 1;
            for(char c: s){
                if(!mp[c]){
                    x = 0;
                    break;
                }
            }
            if(x)ans++;
        }
        return ans;
    }
};
