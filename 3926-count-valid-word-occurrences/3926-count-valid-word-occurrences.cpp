class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {

        string s = "";
        for (const string& chunk : chunks) {
            s += chunk;
        }
        unordered_map<string, int> word_count;
        string current_word = "";
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            
            if (islower(c)) {
                current_word += c;
            } 
            else if (c == '-') {
                bool has_prev = (i > 0);
                bool has_next = (i < n - 1);
                
                if (has_prev && has_next && islower(s[i-1]) && islower(s[i+1])) {

                    current_word += c;
                } else {

                    if (!current_word.empty()) {
                        word_count[current_word]++;
                        current_word = ""; 
                    }
                }
            } 
            else {
                
                if (!current_word.empty()) {
                    word_count[current_word]++;
                    current_word = ""; 
                }
            }
        }
        
        if (!current_word.empty()) {
            word_count[current_word]++;
        }
        
        vector<int> ans;
        for (const string& q : queries) {
            ans.push_back(word_count[q]);
        }
        
        return ans;
    }
};