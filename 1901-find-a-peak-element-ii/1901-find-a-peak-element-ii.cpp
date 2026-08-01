class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1; 

        while (low <= high) {
            int mid = (low + high) / 2;
            int maxRow = 0;
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            bool leftOK = (mid == 0 || mat[maxRow][mid] > mat[maxRow][mid - 1]);
            bool rightOK = (mid == m - 1 || mat[maxRow][mid] > mat[maxRow][mid + 1]);
            if (leftOK && rightOK) {
                return {maxRow, mid};
            }

            else if (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]) {
                high = mid - 1;  
            } else {
                low = mid + 1;
            }
        }
        return {}; 
    }
};