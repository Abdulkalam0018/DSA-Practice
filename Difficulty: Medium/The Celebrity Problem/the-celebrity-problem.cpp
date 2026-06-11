class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int a=0;
            int b=0;
            for(int j=0;j<n;j++)
            {
                a+=mat[i][j];
                b+=mat[j][i];
            }
            if(b==n && a==1) return i;
        }
        return -1;
    }
};