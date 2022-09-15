class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        unordered_map<int, int>mark;
        for(int i = 0; i<changed.size(); i++){
            mark[changed[i]]++;
        }
        
        vector<int>ans;
        if(n%2==1)return {};
        sort(changed.begin(), changed.end());
        
        for(int i = 0; i<n; i++){
            if(mark[changed[i] ]== 0)continue;
            if( mark[changed[i] *2] == 0)return {};
            ans.push_back(changed[i]);
            mark[changed[i] ]--;
            mark[changed[i] *2]--;
        }
        return ans;
    }
};
