class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0")return "0";
        int n = (int)num1.size();
        int m = (int)num2.size();
        vector<int>ans(n+m, 0); // total digit;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                ans[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                ans[i+j] += ans[i+j+1]/10;
                ans[i+j+1]%=10;
            }
        }
        reverse(ans.begin(), ans.end());
        while(ans.back() == 0)ans.pop_back();
        string s;
        for(auto x:ans)s.push_back(x+'0');
        reverse(s.begin(), s.end());
        return s;
    }
};
