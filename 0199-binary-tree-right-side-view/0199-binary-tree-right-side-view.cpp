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
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;

        while(!q.empty())
        {
            int n=q.size();
            int data=-101;

            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                data=it->val;

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                
            }
            if(data!=-101)
            ans.push_back(data);
        }
        return ans;
    }
};