class Solution {
public:
    vector<vector<int>>tar={
        {1,2,3},{4,5,0}
    };
    int slidingPuzzle(vector<vector<int>>& board)
    {
        int dir1[4]={0,0,1,-1};
        int dir2[4]={1,-1,0,0};

        queue<vector<vector<int>>>q;
        if(board==tar) return 0;

        q.push({board});
        int ans=0;

        set<vector<vector<int>>>vis;
        vis.insert(board);

        while(!q.empty())
        {
            int len=q.size();

            ans++;
            while(len--)
            {

                auto it=q.front();
                q.pop();
                for(int i=0;i<2;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(it[i][j]==0){
                            for(int k=0;k<4;k++)
                            {
                                vector<vector<int>>grid=it;
                                int x=i+dir1[k];
                                int y=j+dir2[k];
                                if(x>=0 && x<2 && y>=0 && y<3)
                                {
                                    swap(grid[x][y],grid[i][j]);
                                    if(grid==tar) return ans;
                                    if(!vis.count(grid))
                                    {
                                        q.push(grid);
                                        vis.insert(grid);
                                    }
                                }
                                
                                
                            }
                            break;
                        }
                    }
                }


            }

        }
        return -1;
    }
};