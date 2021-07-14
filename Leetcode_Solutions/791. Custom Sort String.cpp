class Solution {
public:
    string customSortString(string order, string str) {
        string ans;
        map<char, int>mp;
        for(int i = 0; i<str.size(); i++){
            mp[ str[i] ]++;
        }
        for(int i = 0; i<order.size(); i++){
            if(mp[ order[i] ]){
                while(mp[ order[i] ]--){
                    ans+= order[i];
                }
            }
        }
        
        for(int i = 0; i<str.size(); i++){
            if(mp[ str[i] ] > 0)ans+=str[i];
        }
        return ans;
    }
};
