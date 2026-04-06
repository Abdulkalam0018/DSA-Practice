class Solution {
public:

    int minCut(string s) {
        
        int n=s.size();
        vector<vector<int>>pal(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j] &&(j-i+1<=2 || pal[i+1][j-1]))
                {
                    pal[i][j]=1;
                }
            }
        }
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(pal[i][j])
                {
                    dp[i]=min(1+dp[j+1],dp[i]);
                }
            }
        }
        return dp[0]-1;

    }
};