#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;

        // 1. Precompute palindrome lookup table in O(N^2)
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2) {
                        pal[i][j] = true;
                    } else {
                        pal[i][j] = pal[i + 1][j - 1];
                    }
                }
            }
        }

        // 2. 1D DP to find minimum cuts in O(N^2)
        // dp[i] = minimum cuts needed for suffix s[i...n-1]
        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int minCuts = INT_MAX;
            for (int j = i; j < n; j++) {
                if (pal[i][j]) {
                    if (j == n - 1) {
                        minCuts = 0; // entire suffix s[i...n-1] is a palindrome
                    } else {
                        minCuts = min(minCuts, 1 + dp[j + 1]);
                    }
                }
            }
            dp[i] = minCuts;
        }

        return dp[0];
    }
};