class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        sort(s.begin(), s.end());
        while(s.size()>1){
            int y = s.back();
            s.pop_back();
            if(y == s.back()){
                s.pop_back();
            }
            else{
                int x = s.back();
                s.pop_back();
                s.push_back(y - x);
                sort(s.begin(), s.end());
            }
        }
        s.push_back(0);
        return s[0];
    }
};
