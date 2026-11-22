

class Node {
public:
    Node* links[26];
    bool flag;
    string word;

    Node() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
        flag = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }

        node->setEnd();
        node->word = word;
    }
};

class Solution {
public:
    int n, m;
    vector<string> ans;

    void dfs(int i, int j, vector<vector<char>>& b, Node* node) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;

        char ch = b[i][j];

        if (ch == '#' || !node->containsKey(ch)) return;

        node = node->get(ch);

        if (node->isEnd()) {
            ans.push_back(node->word);
            node->flag = false;
        }

        b[i][j] = '#';

        dfs(i + 1, j, b, node);
        dfs(i - 1, j, b, node);
        dfs(i, j + 1, b, node);
        dfs(i, j - 1, b, node);

        b[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        n = board.size();
        m = board[0].size();
        ans.clear();

        Trie t;

        for (auto &w : words) {
            t.insert(w);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, board, t.root);
            }
        }

        return ans;
    }
};
