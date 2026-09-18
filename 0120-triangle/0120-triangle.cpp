class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr)
    {
        int n=tr.size();
        int m=tr[n-1].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));

        dp[0][0]=tr[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j<=i)
                {
                    if(i-1>=0 && i!=j)
                    {
                        dp[i][j]=min(dp[i][j],tr[i][j]+dp[i-1][j]);
                    }
                    if(i-1>=0 && j-1>=0)
                    {
                        dp[i][j]=min(dp[i][j],tr[i][j]+dp[i-1][j-1]);
                    }
                }
            }
        }

        int ans=dp[n-1][0];
        for(auto &x:dp[n-1])
        {
            ans=min(ans,x);
        }
        return ans;
    }
};
/*
2
3 4
6 5 7
4 1 8 3

*/ 