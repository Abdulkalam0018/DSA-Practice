class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; 
        auto maxPath = [&maxSum](TreeNode* root1, auto& maxPath) -> int {
            if (root1 == nullptr) {
                return 0;  
            }

            int leftSum = max(maxPath(root1->left, maxPath), 0);
            int rightSum = max(maxPath(root1->right, maxPath), 0); 
            int localMaxSum = root1->val + leftSum + rightSum;
            maxSum = max(maxSum, localMaxSum);
            return root1->val + max(leftSum, rightSum);
        };
        maxPath(root, maxPath);
        return maxSum;
    }
};