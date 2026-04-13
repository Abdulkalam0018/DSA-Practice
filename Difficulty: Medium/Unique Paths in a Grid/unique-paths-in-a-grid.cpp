class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        if(grid[0][0]==1) return 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n+1,vector<int>(m+1,0));
        ans[1][1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==1 && j==1) continue;
                if(grid[i-1][j-1]==0)
                {
                    ans[i][j]=(ans[i-1][j]+ans[i][j-1]);
                }
            }
        }
        return ans[n][m];
    }
};