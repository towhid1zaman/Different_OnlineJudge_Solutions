class Solution {
public:
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n1 = A.size();
        int n2 = B.size();
        // make sure A<=B
        if(n1 > n2) return findMedianSortedArrays(B, A);
        int low = 0, high = n1;
        int A_left, A_right, B_left, B_right, mx, mn;
        while(low <= high){
            int cut1 = (low + high)/2; // taking some elements from A
            int cut2 = (n1 + n2 + 1)/2 - cut1; // taking some elements from B
            
            A_left = (cut1 == 0 ? INT_MIN : A[cut1 - 1]);
            B_left = (cut2 == 0 ? INT_MIN : B[cut2 - 1]);
            A_right = (cut1 == n1 ? INT_MAX : A[cut1]);
            B_right = (cut2 == n2 ? INT_MAX : B[cut2]);

            
            mx = max(A_left,B_left);
            mn = min(A_right, B_right);
            
            if(A_left <= B_right and B_left <= A_right){
                if((n1+n2)%2==0)return 0.5*(mx+mn);
                else return mx;
            }
            else if(A_left > B_right){
                high = cut1 - 1;
            }
            else low = cut1 + 1;
        }
        return 0.0;
}
};
