class Solution {
public:
    vector<int>dx = {0, 0,1, -1}, dy = {1,-1, 0, 0}; //up,down,right, left
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int id){
        if(i < 0 or j < 0 or i >= n or j >=m or grid[i][j] != 1)return 0;
        grid[i][j] = id;
        int ans = 0;
        for(int d = 0; d<4; d++){
            int x = i+dx[d], y = j+dy[d];
            ans+=dfs(grid, x, y, n, m, id);
        }
        return ans+1;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        if(n==0 or m==0)return 0;
        
        int ans = 0;
        map<int,int>mark;
        int id = 2;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    int island_size = dfs(grid, i, j, n, m, id);
                    mark[id++] = island_size;
                    ans = max(ans, island_size);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    set<int>side;
                    for(int d = 0; d<4; d++){
                         int x = i+dx[d], y = j+dy[d];
                         if(x < 0 or  x>=n or y<0 or y>=m or grid[x][y] == 0)continue;
                         side.emplace(grid[x][y]);
                    }
                    int now = 1; // zero replace with 1
                    for(auto x:side){
                        now += mark[x];
                    }
                    ans = max(ans, now);
                }
            }
        }
        return ans;
    }
};
