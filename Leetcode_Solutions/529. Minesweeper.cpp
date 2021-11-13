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
    int go(TreeNode* root, int &d){
        if(root == NULL)return 0;
        int left = go(root->left, d);
        int right = go(root->right, d);
        d = max(left+right, d);
        
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int d = 0;
        go(root, d);
        return d;
    }
};
