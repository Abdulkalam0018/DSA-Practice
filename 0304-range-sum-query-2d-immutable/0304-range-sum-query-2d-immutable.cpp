class NumMatrix {
public:

    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {


        int n=matrix.size();
        int m=matrix[0].size();
        prefix.assign(n+1,vector<int>(m+1,0));

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                prefix[j][i]=prefix[j-1][i]+matrix[j-1][i-1];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                prefix[i][j]=prefix[i][j-1]+prefix[i][j];
            }
        }
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         cout<<prefix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //cout<<prefix[row1][col1]<<endl;
        return prefix[row2+1][col2+1]-prefix[row1][col2+1]-prefix[row2+1][col1]+prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */