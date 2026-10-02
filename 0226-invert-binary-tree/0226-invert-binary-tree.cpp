class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            swap(it->left, it->right);

            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
        }
        return root;
    }
};