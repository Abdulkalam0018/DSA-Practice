class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long modPow(long long a, long long e) {
        long long r = 1;
        while (e > 0) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        int check = sqrt(n) + 1;

        unordered_map<int, vector<vector<int>>> small;

        for (auto &q : queries) {
            int k = q[2];
            if (k >= check) {
                int l = q[0];
                int r = q[1];
                int v = q[3];

                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                small[k].push_back(q);
            }
        }

        for (auto &x : small) {
            vector<long long> diff(n, 1);

            for (auto &y : x.second) {
                int k = y[2];
                int v = y[3];

                diff[y[0]] = (diff[y[0]] * v) % MOD;

                int step = (y[1] - y[0]) / k;
                int next = y[0] + k * (step + 1);

                if (next < n) {
                    diff[next] = (1LL*diff[next] * modPow(v, MOD - 2)) % MOD;
                }
            }

            int k = x.first;
            for (int i = 0; i < n; i++) {
                if (i >= k) {
                    diff[i] = (1LL*diff[i] * diff[i - k]) % MOD;
                }
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }

        int ans = 0;
        for (auto &x : nums) {
            ans ^= x;
        }
        return ans;
    }
};