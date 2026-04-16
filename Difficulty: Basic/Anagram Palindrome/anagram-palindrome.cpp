class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        unordered_map<char,int>mp;
        for(auto &x:s)
        {
            mp[x]++;
        }
        int cnt=0;
        for(auto &x:mp)
        {
            if(x.second%2) cnt++;
        }
        if(cnt<=1) return true;
        return false;
    }
};