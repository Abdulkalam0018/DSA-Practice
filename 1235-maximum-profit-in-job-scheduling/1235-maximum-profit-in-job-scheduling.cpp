class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        
        map<int,int>mp;

        int n=st.size();
        vector<int>dp(n+1,0);

        using ii=pair<int,pair<int,int>>;
        vector<ii>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({et[i],{st[i],profit[i]}});
        }
        sort(v.begin(),v.end());

        for(int i=1;i<=n;i++)
        {
            auto it=v[i-1];
            int b=it.first;
            int c=it.second.first;
            int d=it.second.second;

            if(mp.size()>=1)
            {
                auto it1=mp.upper_bound(c);
                if(it1!=mp.begin())
                {
                    it1--;
                    int f=(it1->second);
                    dp[i]=max(dp[i-1],d+dp[f]);
                }
                else
                {
                    dp[i]=max(dp[i-1],d);
                }
            }
            else
            {
                dp[i]=max(dp[i-1],d);
            }
            mp[b]=i;
        }
        return dp[n];
    }
};