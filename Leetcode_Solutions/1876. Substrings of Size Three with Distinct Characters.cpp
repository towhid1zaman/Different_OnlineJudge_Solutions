class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = (int)s.size();
        if(n < 3){
            return 0;
        }
        char a = s[0], b = s[1], c = s[2];
        int cnt = (a != b and a!=c and b!=c);
        for(int i = 1; i+2 < n; i++){
            char a = s[i], b = s[i+1], c = s[i+2];
            if(a != b and a!=c and b!=c)cnt++;
        }
        return cnt;
    }
};
