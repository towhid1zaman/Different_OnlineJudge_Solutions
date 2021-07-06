class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)return 0;
        vector<int>a(n+1);
        int mx = 0;
        a[0] = 0;
        a[1] = 1;
        for(int i = 0; i<=n; i++){
            if(2*i <= n)a[2*i] = a[i];
            if((2*i+1) <= n) a[(2*i) +1] = a[i] + a[i+1];
        }
        for(int i = 0; i<=n; i++)mx = max(mx, a[i]);
        return mx;
    }
};
