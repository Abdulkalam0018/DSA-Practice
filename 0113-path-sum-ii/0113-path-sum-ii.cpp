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
    void fun(TreeNode* node,int sum,vector<int>v,vector<vector<int>>&ans,int ts)
    {
        if(!node)
        {
            return ;
        }
        if(!node->left && !node->right)
        {
            sum+=node->val;
            if(sum==ts)
            {
                v.push_back(node->val);
                ans.push_back(v);
                
                return ;
            }
            else
            {
                return ;
            }

        }
        v.push_back(node->val);
        sum+=node->val;
        fun(node->left,sum,v,ans,ts);
        fun(node->right,sum,v,ans,ts);

    }
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        vector<vector<int>>ans;
        vector<int>v;
        fun(root,0,v,ans,ts);
        return ans;
    }
};