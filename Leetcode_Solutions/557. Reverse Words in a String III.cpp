class Solution {
public:
    string reverseWords(string s) {
        int n = (int)s.length();
        string ans ="";
        stringstream ss;
        ss << s;
        string a;
        while(ss >> a){
            reverse(a.begin(), a.end());
            ans+=(a+" ");
        }
        ans.pop_back();
        return ans;
    }
};
