class Solution {
public:
    int findTheLongestSubstring(string s)
    {
        unordered_map<int,int>mp;

        int n=s.size();
        // for(int i=0;i<=31;i++)
        // {
        //     mp[i]=-1;
        // }   
        mp[0]=-1;
        int state=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                state=state^(1<<0);
                if(mp.find(state)==mp.end())
                {
                    mp[state]=i;
                }
            }
            else if(s[i]=='e')
            {
                state=state^(1<<1);
                if(mp.find(state)==mp.end())
                {
                    mp[state]=i;
                }
            }
            else if(s[i]=='u')
            {
                state=state^(1<<4);
                if(mp.find(state)==mp.end())
                {
                    mp[state]=i;
                }
            }
            else if(s[i]=='i')
            {
                state=state^(1<<2);
                if(mp.find(state)==mp.end())
                {
                    mp[state]=i;
                }
            }
            else if(s[i]=='o')
            {
                state=state^(1<<3);
                if(mp.find(state)==mp.end())
                {
                    mp[state]=i;
                }
            }
            ans=max(ans,i-mp[state]);
        } 
        return ans;
    }

};