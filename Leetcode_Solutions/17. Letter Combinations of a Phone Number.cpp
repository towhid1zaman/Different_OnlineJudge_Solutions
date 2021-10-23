class Solution {
public:
    vector<string>ans;
    vector<string>id = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    void comb(int pos, string s, int k, string &cur){
        if(pos == k){
            ans.push_back(cur);
            return;
        }
        for(char c : id[s[pos]-'0']){
            cur[pos] = c;
            comb(pos+1, s, k, cur);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return ans;
        int k = (int)digits.size();
        string t=digits;
       // cout << s << endl;
        comb(0, digits, k, t);
        return ans;
    }
};
