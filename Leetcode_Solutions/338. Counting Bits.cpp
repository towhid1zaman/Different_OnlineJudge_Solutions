class Solution {
public:
    int Bit(int n){
        int cnt = 0;
        while(n){
            if(n%2)cnt++;
            n/=2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>bit;
        for(int i = 0; i<=n; i++){
            bit.push_back(Bit(i));
        }
        return bit;
    }
};
