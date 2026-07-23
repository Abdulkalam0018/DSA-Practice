class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {}; // Handle the case when root is null
        }

        deque<TreeNode*> de;
        de.push_back(root);
        vector<vector<int>> result;
        bool leftToRight = true;

        while (!de.empty()) {
            int n = de.size();
            vector<int> level;

            if (leftToRight) {
                for (int i = 0; i < n; ++i) {
                    TreeNode* node = de.front();
                    de.pop_front();
                    level.push_back(node->val);

                    if (node->left) de.push_back(node->left);
                    if (node->right) de.push_back(node->right);
                }
            } else {
                for (int i = 0; i < n; ++i) {
                    TreeNode* node = de.back();
                    de.pop_back();
                    level.push_back(node->val);

                    if (node->right) de.push_front(node->right); // right child first
                    if (node->left) de.push_front(node->left);   // then left child
                }
            }

            result.push_back(level);
            leftToRight = !leftToRight; // Toggle direction for next level
        }

        return result;
    }
};