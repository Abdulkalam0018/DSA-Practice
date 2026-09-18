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
    void fun(TreeNode* root, int ts,vector<vector<int>>&ans,vector<int>&k,int sum)
    {
        if(!root) return ;
        if(!root->left && !root->right)
        {
            sum+=root->val;
            if(sum==ts)
            {
                k.push_back(root->val);
                ans.push_back(k);
                k.pop_back();
            }
            return ;
        }
        sum+=root->val;
        k.push_back(root->val);
        fun(root->left,ts,ans,k,sum);
        fun(root->right,ts,ans,k,sum);
        k.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        
        vector<vector<int>>ans;
        vector<int>k;
        if(!root) return ans;
        fun(root,ts,ans,k,0);
        return ans;
    }
};