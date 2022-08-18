class Solution {
public:
    string reverseOnlyLetters(string s) {
        int startPos = 0, endPos = (int)s.size()-1;
        while(startPos <= endPos){
            if(!isalpha(s[startPos])){
                startPos++;
            }
            else if(!isalpha(s[endPos])){
                endPos--;
            }
            else{
                char temp = s[startPos];
                s[startPos] = s[endPos];
                s[endPos] = temp;
                startPos++;
                endPos--;
            }
        }
        return s;
    }
};
