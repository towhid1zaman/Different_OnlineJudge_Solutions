class Solution {
public:
    
    int SIX(string s, int i){
        if(s[i] == 'I' and s[i+1] == 'V'){ //IV = 4
            return 4;
        }
        if( s[i] == 'I' and s[i+1] == 'X'){ //IX = 9
            return 9;
        }
        if(s[i] == 'X' and s[i+1] == 'L'){ //XL = 40
            return 40;
        }
        if(s[i] == 'X' and s[i+1] == 'C'){ //XC = 90
            return 90;
        }
        if(s[i] == 'C' and s[i+1] == 'D'){ //CD = 400
            return 400;   
        }
        if(s[i] == 'C' and s[i+1] == 'M'){ //CM = 900
            return 900;
        }
        else return 0;
    }
    
    int romanToInt(string s){
        int ans = 0;
        int n = (int)s.size();
        s+="#";
        for(int i = 0; i < n;){
            int cur = SIX(s, i);
            if(cur > 0){
                ans += cur;
                i += 2;
            }
            else{
                if(s[i] == 'I')ans += 1;
                if(s[i] == 'V')ans += 5;
                if(s[i] == 'X')ans += 10;
                if(s[i] == 'L')ans += 50;
                if(s[i] == 'C')ans += 100;
                if(s[i] == 'D')ans += 500;
                if(s[i] == 'M')ans += 1000;
                i++;
            }
        }
        return ans;
    }
};
