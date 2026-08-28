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
    bool ans(TreeNode* node,int sum, int ts)
    {
        if(!node) return false;
        if(!node->left && !node->right)
        {
            sum+=node->val;
            if(sum==ts) return true;
            return false;
        }

        sum+=node->val;
        bool ans1=false;
        ans1|=ans(node->left,sum,ts);
        ans1|=ans(node->right,sum,ts);
        return ans1;
    }
    bool hasPathSum(TreeNode* root, int ts) {
        if(!root) return false;
        return ans(root,0,ts);
    }
};