class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = (int)a.size();
        multiset<int>m;
        int l = 0, r = k;
        vector<int>ans;
        for(int i = 0; i<k; i++){
            m.insert(a[i]);
        }
        while(r <= n){
            auto it = m.end();
            ans.push_back(*(--it));
            m.erase(m.find(a[l]));
            if(r < n)m.insert(a[r]);
            l++, r++;
        }
        return ans;
    }
};
