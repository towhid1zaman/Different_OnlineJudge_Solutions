void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int startPos = 0, curPos = 0, endPos = (int)A.size() - 1;
    while(curPos <= endPos){
        if(A[curPos] == 0){
            swap(A[startPos++], A[curPos++]);
        }
        else if(A[curPos] == 1){
            curPos++;
        }
        else{
            swap(A[curPos], A[endPos--]);
        }
    }
}
