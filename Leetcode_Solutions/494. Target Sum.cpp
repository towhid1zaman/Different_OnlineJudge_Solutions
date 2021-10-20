class Solution {
public:
    int ways = 0;
    void count(vector<int>&a, int pos, int tot, int target){
        if(pos == a.size()){
            if(tot == target){
                ways++;
                return;
            }
            else return;
        }
            count(a, pos+1, tot+a[pos], target);
            count(a, pos+1, tot-a[pos], target);
    }
    int findTargetSumWays(vector<int>& a, int target) {
        count(a, 0, 0,target);
        return ways;
    }
};
