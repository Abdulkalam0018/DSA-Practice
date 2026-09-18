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
    int diameterOfBinaryTree(TreeNode* root) {
        int globalmax=0;
        if(!root) return globalmax;
        fun(root,globalmax);
        return globalmax;
    }
    int fun(TreeNode* root, int &globalmax)
    {
        if(!root) return 0;
        int lh=fun(root->left,globalmax);
        int rh=fun(root->right,globalmax);

        globalmax=max(globalmax,lh+rh);
        return 1+max(lh,rh);
    }
};