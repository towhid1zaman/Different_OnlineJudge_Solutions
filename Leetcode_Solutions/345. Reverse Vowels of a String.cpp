class Solution {
public:
    bool is_vowel(char c){
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U';
    }
    string reverseVowels(string s) {
    int l = 0, r = (int)s.size() - 1;
    while(l <= r){
        //dbug(s[l], s[r], is_vowel(s[l]), is_vowel(s[r]));
        while(l < r and !is_vowel(s[r]))r--;
        while(l < r and !is_vowel(s[l]))l++;
        swap(s[l], s[r]);
        l++, r--;
    }
    return s;
    }
};
