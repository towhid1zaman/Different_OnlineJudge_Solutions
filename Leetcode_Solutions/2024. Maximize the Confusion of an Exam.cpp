class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = -1, maxChar = -1;
        map<char, int>sCnt;
        int startPos = 0;
        for(int endPos = 0; endPos < answerKey.size(); endPos++){
            sCnt[ answerKey[endPos] ]++;
            maxChar = max(maxChar, sCnt[ answerKey[endPos] ]);
            
            while((endPos - startPos + 1) - maxChar > k){
                sCnt[ answerKey[startPos] ]--;
                startPos++;
            }
            ans = max(ans, endPos - startPos + 1);
        }
        return ans;
    }
};
