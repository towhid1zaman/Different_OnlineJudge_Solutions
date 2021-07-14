class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss << s;
        string a;
        vector<string>ans;
        while(ss>>a){
            ans.push_back(a);
        }
        reverse(ans.begin(), ans.end());
        string t="";
        for(auto x:ans)t+=(x+" ");
        t.pop_back();
        return t;
    }
};
