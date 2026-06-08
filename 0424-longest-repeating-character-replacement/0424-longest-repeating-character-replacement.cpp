class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(256, 0);
        int max_freq = 0;
        int ans = 0;
        int i = 0;

        for (int j = 0; j < s.size(); j++) {
            freq[s[j]]++;
            
            max_freq = max(max_freq, freq[s[j]]);

            while ((j - i + 1) - max_freq > k) {
                freq[s[i]]--;
                i++;

            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};