class Solution {
public:
    vector<int>color;
    bool dfs(vector<vector<int>>& graph, int v){
        color[v] = 1;
        for(auto u: graph[v]){
            if(color[u] == 0){
                if(dfs(graph,u))return true;
            }
            else if(color[u] == 1)return true;
        }
        color[v] = 2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, 0);
        for(int i = 0; i<n; i++){
            if(color[i] == 0){
                dfs(graph, i);
            }
        }
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(color[i] == 2)ans.push_back(i);
        }
        return ans;
    }
};
