class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int n = (int)a.size();
        int m = (int)b.size();
        int i = 0, j = 0, c = 0;
        while(i<n or j<m or c){
            int x = 0;
            if(i < n and a[n-i-1] == '1')x = 1;
            int y = 0;
            if(j < m and b[m-j-1] == '1')y = 1;
            int result = (x+y+c)%2;
            ans = to_string(result) + ans;
            c = (x+y+c)/2;
            i++, j++;
        }
        return ans;        
    }
};
