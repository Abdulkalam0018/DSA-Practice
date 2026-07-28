class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int a=matrix[i-1][j-1];

                if(a==1)
                {
                    dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
                    ans+=dp[i][j];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
};