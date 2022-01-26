class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
    int n = v.size();
    int one = 0;
    for(int i = 0; i<n; i++){
        if(v[i] == 1)one = 1;
        if(v[i]<=0 or v[i]>n){
            v[i] = 1;
        }
    }
    if(!one){
        return 1;
    }
    for(int i = 0;i<n; i++){
        int ind = abs(v[i]) - 1;
        if(v[ind]>0)v[ind] = -v[ind];
    }
    int ans = n+1;
    for(int i = 0; i<n;i++){
        if(v[i] > 0){
            ans = i+1;
            break;
        }
    }
    return ans;
    }
};
