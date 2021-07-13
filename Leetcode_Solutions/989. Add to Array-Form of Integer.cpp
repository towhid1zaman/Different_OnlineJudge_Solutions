class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>kum;
        int i = (int)num.size() - 1;
        int rem = 0, sum = 0, rest = 0, last;
        vector<int>ans;
        while(k){
            int r = (k%10);
            if(i < 0)last = 0;
            else last = num[i];
            sum = last+r;
            if(rest)sum+=rest;
            rest = 0;
            if(sum > 9)rest = sum/10,sum %= 10;
            ans.push_back(sum);
            k/=10;
            i--;
        }
        int ok = 0;
        for(int j = i; j>=0; j--){
            int sum = num[j] + rest;
            rest = 0;
            if(sum > 9)rest = sum/10,sum %= 10;
            ans.push_back(sum);
        }
        if(rest)ans.push_back(rest);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
