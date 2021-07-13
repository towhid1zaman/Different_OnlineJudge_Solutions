class Solution {
public:
    vector<int> plusOne(vector<int>& num2) {
        vector<int>num1; num1.push_back(1);
        vector<int>ans;
        int n = (int)num1.size();
        int m = (int)num2.size();
        int i, j;
        int sum = 0, last = 0, rem = 0, rest = 0;
        for(i = n-1, j = m-1; i>=0 and j>=0;i--, j--){
            sum = (num1[i]) + (num2[j]);
            sum+=rest;
            rest = 0;
            if(sum > 9)rest = sum/10,sum %= 10;
            ans.push_back(sum);
        }
       for(; j >=0 ; j --){
            sum = num2[j];
            sum+=rest;
            rest = 0;
            if(sum > 9)rest = sum/10,sum %= 10;
            ans.push_back(sum);
        }
        cout << rest << endl;
        if(rest > 0)ans.push_back(rest);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
