class Node {
public:
    Node* links[2];

    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
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
    void insert(Node* root, int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containkey(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMaxXor(Node* root, int num) {
        Node* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if (node->containkey(opposite)) {
                maxXor |= (1 << i);
                node = node->get(opposite);
            } else {
                node = node->get(bit);
            }
        }

        return maxXor;
    }

    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();

        for (int num : nums) {
            insert(root, num);
        }

        int best = 0;

        for (int num : nums) {
            best = max(best, getMaxXor(root, num));
        }

        return best;
    }
};