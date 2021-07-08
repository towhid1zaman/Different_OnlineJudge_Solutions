class Solution {
public:
    //Backtracking

    bool ok(int n, int row, int col, std::vector<vector<int>>&grid){
       //check up;
       for(int i = row; i>=0; i--){
        if(grid[i][col] == 1)return false;
       }

       //check down
       for(int i = row; i<n; i++){
        if(grid[i][col] == 1)return false;
       }

       //check left
       for(int i = col; i<n; i++){
        if(grid[row][i] == 1)return false;
       }

       //check right
       for(int i = col; i>=0; i--){
        if(grid[row][i] == 1)return false;
       }

       //check upper left diagonal
       for(int i = row, j = col; i>=0 and j >=0; i--, j--){
        if(grid[i][j] == 1)return false;
       }

       //check upper right diagonal
       for(int i = row, j = col; i>=0 and j < n; i--, j++){
        if(grid[i][j] == 1)return false;
       }

       //check lower left diagonal
       for(int i = row, j = col; i<n and j >= 0; i++, j--){
        if(grid[i][j] == 1)return false;
       }

       //check lower right diagonal
       for(int i = row, j = col; i<n and j<n; i++, j++){
        if(grid[i][j] == 1)return false;
       }

       return true;
    }

    int tot_path = 0;
    std::vector< std::vector<string> > paths;
    void go(int row,int n,std::vector<vector<int>>&grid){
        if(row >= n){
            vector<string>v;
            for(int i = 0; i<n; i++){
                string a;
                for(int j = 0; j<n; j++){
                    if(grid[i][j])a.push_back('Q');
                    else a.push_back('.');
                }
                v.push_back(a);
            }
            paths.push_back(v);
            tot_path++;
            return;
        }
        for(int i = 0; i<n; i++){
            if(ok(n, row, i, grid)){
                grid[row][i] = 1;
                go(row+1,n, grid);
                grid[row][i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        std::vector<vector<int>>grid(n, vector<int>(n, 0));
        go(0, n, grid);
        return paths;
    }
};
