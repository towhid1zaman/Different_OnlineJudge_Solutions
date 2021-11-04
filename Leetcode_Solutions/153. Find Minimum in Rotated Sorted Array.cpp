class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, h = (int)a.size() - 1;
        while(l < h){
            int m = (l+h)>>1;
            if(a[h] < a[m]){
                l = m+1;
            }
            else h = m;
        }
        return a[l];
    }
};
