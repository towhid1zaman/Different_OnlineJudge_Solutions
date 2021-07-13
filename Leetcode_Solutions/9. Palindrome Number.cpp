class Solution {
public:
    bool isPalindrome(int n) {
        string s;
        int ok = 0;
        if(n < 0)ok = 1, n*=-1ll;
        while(n){
            int last = n%10;
            s.push_back(last+'0');
            n/=10;
        }
        if(ok)s.push_back('-');
        reverse(s.begin(), s.end());
        string t = s;
        reverse(t.begin(), t.end());
        return s==t;
        
    }
};
