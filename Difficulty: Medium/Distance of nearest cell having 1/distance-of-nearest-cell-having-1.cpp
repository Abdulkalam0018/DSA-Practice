class Solution {
  public:
    int dif1[4]={0,0,1,-1};
    int dif2[4]={1,-1,0,0};
    bool check(int x,int y,int n,int m)
    {
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0)),ans(n,vector<int>(m,0));
        
        using state=pair<int,int>;
        queue<state>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto it=q.front();
            int a=it.first;
            int b=it.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=a+dif1[i];
                int y=b+dif2[i];
                if(check(x,y,n,m) && vis[x][y]==0)
                {
                    vis[x][y]=1;
                    q.push({x,y});
                    ans[x][y]=ans[a][b]+1;
                }
            }
        }
        return ans;
         
    }
};