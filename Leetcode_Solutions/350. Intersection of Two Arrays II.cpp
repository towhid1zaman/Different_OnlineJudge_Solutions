class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        map<int, int>f, s;
        for(int i = 0; i<a.size(); i++)f[a[i]]++;
        vector<int>v;
        for(int i = 0; i<b.size(); i++)s[ b[i] ]++;
        set<int>S;
        for(auto x:a)S.insert(x);
        for(auto x:S){
            int mn = min(f[x], s[x]);
            while(mn--){
                v.push_back(x);
            }
        }
        return v;
    }
};
