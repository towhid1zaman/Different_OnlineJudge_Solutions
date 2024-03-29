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
    TreeNode *go(vector<int>& nums,int l, int r){
        if(l > r)return nullptr;
        int mid = (l+r+1)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = go(nums, l, mid-1);
        root->right = go(nums,mid+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = (nums.size());
        return go(nums, 0, n-1);
    }
};
