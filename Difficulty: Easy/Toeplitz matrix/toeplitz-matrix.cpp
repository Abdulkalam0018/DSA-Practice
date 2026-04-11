class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int n=(int)mat.size();
        int m=(int)mat[0].size();
        int row=0;
        for(int i=m-1;i>=0;i--)
        {
            int x=i;
            int y=row;
            int prev=mat[y][x];
            while(x+1<m && y+1<n)
            {
                if(mat[y+1][x+1]!=prev)
                {
                    return false;
                }
                x++;
                y++;
            }
        }
        
        int col=0;
        for(int i=1;i<n;i++)
        {
            int x=i;
            int y=col;
            int prev=mat[x][y];
            while(x+1<n && y+1<m)
            {
                if(mat[x+1][y+1]!=prev)
                {
                    return false;
                }
                x++;
                y++;
            }
        }
        return true;
    }
};