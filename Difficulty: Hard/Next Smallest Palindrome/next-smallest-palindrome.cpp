class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = (int)num.size();
        vector<int> ans = num;

        for (int i = 0; i < n / 2; i++) {
            ans[n - 1 - i] = ans[i];
        }

        if (ans > num) return ans;

        int carry = 1;
        int i = (n - 1) / 2;   
        int j = n / 2;         

        while (i >= 0 && carry) {
            int val = ans[i] + carry;
            ans[i] = val % 10;
            carry = val / 10;
            ans[j] = ans[i]; 
            i--;
            j++;
        }
        if (carry) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }

        return ans;
    }
};