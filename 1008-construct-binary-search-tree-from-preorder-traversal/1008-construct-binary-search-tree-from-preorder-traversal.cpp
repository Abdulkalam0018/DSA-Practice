class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* child = new TreeNode(preorder[i]);
            

            if (child->val < st.top()->val) {
                st.top()->left = child;
            } 
            else {
                TreeNode* parent = st.top();
                while (!st.empty() && st.top()->val < child->val) {
                    parent = st.top();
                    st.pop();
                }
                parent->right = child;
            }
            st.push(child);
        }

        return root;
    }
};