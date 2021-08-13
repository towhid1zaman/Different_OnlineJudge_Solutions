class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int b[n][m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(a[i][j]==0){
                    b[i][j] = 0;
                }
                else b[i][j] = 1;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                    if(b[i][j] == 0){
                        for(int k = 0; k<n; k++){
                            a[k][j] = 0;
                        }
                        for(int k = 0; k<m; k++){
                            a[i][k] = 0;
                        }
                }
            }
        }
    }
};
