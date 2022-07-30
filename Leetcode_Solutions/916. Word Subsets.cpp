class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        map<char, int>charCount;
        for(char c: words2[0]){
                charCount[c]++;
        }
        for(int i = 1; i<words2.size(); i++){
            string word = words2[i];
            map<char, int>temp;
            for(char c: word){
                temp[c]++;
                if(charCount[c] < temp[c])charCount[c]++;
            }
        }
        
        for(string word:words1){
            bool possible = true;
            map<char, int>cur;
            for(char c: word){
                cur[c]++;
            }
            for(int i = 0; i<26; i++){
                if(charCount[i+'a'] > cur[i+'a']){
                    possible = false;
                }
            }
            if(possible)ans.push_back(word);
        }
        return ans;
    }
};
