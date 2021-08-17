/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* r, int cur){
        if(r==NULL)return;
        if(r->val >= cur){
            ans++;
            cur = r->val;
        }
        dfs(r->left, cur);
        dfs(r->right, cur);
    }
    int goodNodes(TreeNode* r) {
        if(r == NULL)return 0;
        dfs(r, INT_MIN);
        return ans;
    }
};
