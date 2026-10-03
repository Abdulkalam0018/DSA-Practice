class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<int> xs(n);
        vector<int> a(n);                      
        for (int i = 0; i < n; i++) {
            xs[i] = points[i][0];
            a[i] = points[i][0] + points[i][1];
        }

        int LOG = 32 - __builtin_clz(n);
        vector<vector<int>> sp(LOG, vector<int>(n));
        sp[0] = a;
        for (int p = 1; p < LOG; p++)
            for (int i = 0; i + (1 << p) <= n; i++)
                sp[p][i] = max(sp[p-1][i], sp[p-1][i + (1 << (p-1))]);

        auto query = [&](int l, int r) {        
            int p = 31 - __builtin_clz(r - l + 1);
            return max(sp[p][l], sp[p][r - (1 << p) + 1]);
        };

        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            int hi = upper_bound(xs.begin(), xs.end(), xs[i] + k) - xs.begin() - 1;
            if (hi <= i) continue;
            ans = max(ans, (points[i][1] - xs[i]) + query(i + 1, hi));
        }
        return ans;
    }
};