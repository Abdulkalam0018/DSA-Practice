class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int>freq(3,0);
        int n=s.size();
        int cnt=0;

        int ans=0;

        int i=0;

        for(int j=0;j<n;j++)
        {
            freq[s[j]-'a']++;
            if(freq[s[j]-'a']==1)
            {
                cnt++;
            }
            while(cnt==3)
            {
                ans+=0LL+n-j;
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0) cnt--;
                i++;
            }
        }
        return ans;

    }
};