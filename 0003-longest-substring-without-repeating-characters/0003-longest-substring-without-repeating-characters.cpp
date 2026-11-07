class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        vector<int>freq(256,0);

        int j=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
            while( j<i && freq[s[i]]>1)
            {
                freq[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
        
    }
};