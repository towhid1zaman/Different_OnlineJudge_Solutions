class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>s;
        for(int x: nums){
            s.push_back(to_string(x));
        }
        sort(s.begin(), s.end(),[](string &s1, string &s2){
            return s1+s2 > s2+s1;
        });
        string res="";
        for(auto x:s)res+=x;
        reverse(res.begin(), res.end());
        while(res.back() =='0' and res.size() > 1)res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
