class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mark;
        vector<double>a;
        for(int i:nums1){
            a.push_back(i);
            mark[i] = 1;
        }
        for(int i:nums2){
                a.push_back(i);
        }
        sort(a.begin(), a.end());
        int n = (int)a.size();
        if(n%2 == 0){
            int mid = n/2;
            return (double)((double)(a[mid]+a[mid-1])/2);
        }
        else{
            int mid = n/2;
            return (double)a[mid];
        }
    }
};
