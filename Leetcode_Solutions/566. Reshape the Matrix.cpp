class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        
        if(n == r and m == c)return mat;
        if(n*m != r*c){
            return mat;
        }
        std::vector<int> v;
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    v.push_back(mat[i][j]);
                }
            }
            reverse(v.begin(), v.end());
            std::vector< std::vector<int> > ans;
            for(int i = 0; i<r; i++){
                std::vector<int> a;
                a.clear();
                for(int j = 0; j<c; j++){
                    a.push_back(v.back());
                    v.pop_back();
                }
                ans.push_back(a);
            }

            return ans;
    }
};
