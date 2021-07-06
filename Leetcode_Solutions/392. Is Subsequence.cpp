class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, ok = 0;
        for(int i= 0; i<t.size(); i++){
            if(t[i]==s[j])j++;
            if(j == (int)s.size()){
                ok = 1;
                break;
            }
        }
        if(s.empty() and t.empty())ok = 1;
        if(ok)return true;
        else return false;
    }
};
