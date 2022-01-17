class Solution {
public:
    string leftJustified(std::vector<string>words, int dif, int i, int j){
        int spaceOnRight = dif - (j - i - 1);
        string cur = words[i];
        for(int k = i+1; k<j; k++){
            cur += ' '+words[k];
        }
        while(spaceOnRight--)cur.push_back(' ');
        return cur;
    }

    string middleJustified(std::vector<string>words, int dif, int i, int j){
        int spaceNeeded = j-i-1;
        int spaces = dif/spaceNeeded;
        int extraSpaces = dif%spaceNeeded;
        string cur = words[i];
        for(int k = i+1; k<j; k++){
            int spacesToApply = spaces + (extraSpaces-- > 0 ? 1 : 0);
            while(spacesToApply--)cur.push_back(' ');
            cur+=words[k];
        }
        return cur;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
            std::vector<string> ans;
        int i = 0, n = words.size();
        while(i < n){
            int j = i+1;
            int linelength = words[i].size();
            while(j < n and (linelength + words[j].size() + (j-i-1)) < maxWidth){
                linelength += words[j].size();
                j++;
            }
            int dif = maxWidth - linelength;
            int numberOfwords = j-i;
            if(numberOfwords == 1 or j>=n){
                ans.push_back(leftJustified(words, dif, i, j)); //right side e space
            }
            else{
                ans.push_back(middleJustified(words, dif, i, j));// middle side e space
            }
            i = j;
        }
        return ans;
    }
};
