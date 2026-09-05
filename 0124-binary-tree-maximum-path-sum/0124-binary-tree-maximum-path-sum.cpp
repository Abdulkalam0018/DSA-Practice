class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN; 
        findMax(root, max_sum);
        return max_sum;
    }

private:
    int findMax(TreeNode* node, int& max_sum) {
        if (node == nullptr) {
            return 0;
        }

        int left_sum = max(0, findMax(node->left, max_sum));
        int right_sum = max(0, findMax(node->right, max_sum));
        int current_path_sum = node->val + left_sum + right_sum;
        max_sum = max(max_sum, current_path_sum);

        return node->val + max(left_sum, right_sum);
    }
};