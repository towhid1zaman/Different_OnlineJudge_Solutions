class Solution {
public:
    string reversePrefix(string word, char ch) {
        int startPos = 0, endPos= -1;
        for(int i = 0; i<(int)word.size(); i++){
            if(word[i] == ch){
                endPos = i;
                break;
            }
        }
        if(endPos == -1)return word;
        while(startPos<=endPos){
            char temp = word[startPos];
            word[startPos++] = word[endPos];
            word[endPos--] = temp;
        }
        return word;
    }
};
