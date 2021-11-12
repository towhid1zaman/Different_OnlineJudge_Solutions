class Solution {
public:
string reorganizeString(string s) {
    vector<int>cnt(27, 0);
    char mx_char; int mx_frq = 0;
    for(char c:s){
        cnt[c-'a']++;
        if(cnt[c-'a'] > mx_frq){
            mx_frq = cnt[c-'a'];
            mx_char = c;
        }
    }
    string t="";
    int n = s.size();
    if(mx_frq>((n+1)/2))return t;
    char ans[n+1];
    int ind = 0;
    while(cnt[mx_char-'a'] > 0){
        ans[ind] = mx_char;
        ind+=2;
        cnt[mx_char-'a']--;
    }
    for(int i = 0; i<27; i++){
        while(cnt[i] > 0){
            if(ind >= n)ind = 1;
            ans[ind] = i+'a';
            ind+=2;
            cnt[i]--;
        }
    }
    for(int i = 0; i<n;i++){
        t.push_back(ans[i]);
    }
    return t;
}
};
