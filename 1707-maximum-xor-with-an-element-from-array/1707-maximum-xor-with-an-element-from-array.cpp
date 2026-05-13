class Node {
public:
    Node* links[2];
    bool flag;

    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
        flag = false;
    }

    bool containkey(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Solution {
public:
    Node* root = new Node();

    void insert(int a) {
        Node* dummy = root;

        for (int k = 31; k >= 0; k--) {
            int bit = (a >> k) & 1;

            if (!dummy->containkey(bit)) {
                dummy->put(bit, new Node());
            }

            dummy = dummy->get(bit);
        }
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        sort(nums.begin(), nums.end());

        int n = q.size();
        int m = nums.size();

        for (int i = 0; i < n; i++) {
            q[i].push_back(i);
        }

        sort(q.begin(), q.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> ans(n, -1);

        int i = 0;
        int cnt = 0;

        for (int j = 0; j < n; j++) {
            int x = q[j][0];
            int limit = q[j][1];
            int index = q[j][2];

            while (i < m && nums[i] <= limit) {
                insert(nums[i]);
                i++;
                cnt++;
            }

            if (cnt != 0) {
                Node* dummy = root;
                int b = 0;

                for (int k = 31; k >= 0; k--) {
                    int bit = (x >> k) & 1;
                    int oppo = 1 - bit;

                    if (dummy->containkey(oppo)) {
                        b = b | (1 << k);
                        dummy = dummy->get(oppo);
                    } else {
                        dummy = dummy->get(bit);
                    }
                }

                ans[index] = b;
            }
        }

        return ans;
    }
};