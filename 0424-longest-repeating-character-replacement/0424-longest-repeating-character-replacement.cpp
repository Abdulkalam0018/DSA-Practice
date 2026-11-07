class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n=s.size();
        if(n==0) return 0;

        int ans=1;

        vector<int>freq(26,0);
        int mx=0;

        int j=0;
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'A']++;
            if(freq[s[i]-'A']>mx) mx=freq[s[i]-'A'];

            if(i-j+1-mx>k)
            {
                freq[s[j]-'A']--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;

    }
};