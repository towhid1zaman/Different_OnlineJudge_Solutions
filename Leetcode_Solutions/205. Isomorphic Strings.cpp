class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        if(n != m){
            return false;
        }
        
        vector<int>pos(257, 0), pot(257, 0);
        int ans = 1;
        for(int i = 0; i<n; i++){
            if(pos[s[i]] != pot[t[i]])ans = 0;
            pos[s[i]]=i+1;
            pot[t[i]]=i+1;
        }
        return ans ? true : false;
    }
};
