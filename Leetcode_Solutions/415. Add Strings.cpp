class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int n = (int)num1.size();
        int m = (int)num2.size();
        
        if(n > m)swap(n, m), swap(num1, num2);
        int i, j;
        int sum = 0, last = 0, rem = 0, rest = 0;
        for(i = n-1, j = m-1; i>=0 and j>=0;i--, j--){
            sum = (num1[i]-'0') + (num2[j]-'0');
            sum+=rest;
            rest = 0;
            if(sum > 9)rest = sum/10,sum %= 10;
            ans+=(to_string(sum));
        }
        for(; j >=0 ; j --){
            sum = num2[j]-'0';
            sum+=rest;
            rest = 0;
            if(sum > 9)rest = sum/10,sum %= 10;
            ans+=(to_string(sum));
        }
        if(rest)ans+=(to_string(rest));
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
