int Solution::diffPossible(vector<int> &A, int B) {
   int ans = 0;
   int firstPos = 0, secondPos = 1;
   while(firstPos < A.size() and secondPos < A.size()){
       if(A[secondPos] - A[firstPos] == B and firstPos != secondPos){
           ans = 1;
           break;
       }
       if(A[secondPos] - A[firstPos] > B)firstPos++;
       else secondPos++;
   }
    return ans;
}
