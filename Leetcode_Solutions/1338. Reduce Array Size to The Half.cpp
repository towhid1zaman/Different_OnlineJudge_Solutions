class Solution {
public:
    int minSetSize(vector<int>& arr) {
        std::map<int,int> mp;
        int n = (int)arr.size();

        for(int i = 0; i<n; i++){
            mp[ arr[i] ]++;
        }

        std::vector<int> v;
        for(auto x:mp){
            v.push_back(x.second);
        }
        sort(v.begin(), v.end());
        int ans = 0, t = 0;
        while(ans < (n/2)){
            ans+=v.back();
            v.pop_back();
            t++;
        }

        return t;
    }
};
