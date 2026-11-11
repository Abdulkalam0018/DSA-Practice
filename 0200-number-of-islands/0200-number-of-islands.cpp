class Solution {
public:
    vector<int>dir1={1,-1,0,0};
    vector<int>dir2={0,0,-1,1};
    void dfs(vector<vector<int>>&vis,vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        if((i<n && j<m) && (vis[i][j]==1 || grid[i][j]=='0' )) return ;

        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int x=dir1[k]+i;
            int y=dir2[k]+j;
            if((x<n && y<m && x>=0 && y>=0)&& (vis[x][y]==0 && grid[x][y]=='1'))
            {
              
                dfs(vis,grid,x,y,n,m);
            }

        }

    }
    int numIslands(vector<vector<char>>& grid) {
        
        int ans=0;

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
                    //cout<<i<<" "<<j<<endl;
                    ans++;
                    dfs(vis,grid,i,j,n,m);
                }
            }
        }
        return ans;
    }
   
};