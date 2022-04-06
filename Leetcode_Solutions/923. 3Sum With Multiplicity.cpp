class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
        int ans = 0;
        int mod = 1e9 + 7;
        unordered_map<int, int>cnt;
        for(int i = 0; i<a.size(); i++){
            ans = (ans + cnt[target - a[i]])%mod;
            for(int j = 0; j<i; j++){
                cnt[a[i] + a[j]]++;
            }
        }
        return ans;
    }
};
