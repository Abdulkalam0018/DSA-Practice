class Solution {
  public:
    int eggDrop(int n, int k) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(k+1));
        
        for(int i=0;i<=k;i++) dp[1][i]=i;
        
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=n;i++) dp[i][1]=1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                int ans=INT_MAX;
                
                int low=1;
                int high=j;
                while(low<=high)
                {
                    int mid=(low+high)/2;
                    int b=dp[i-1][mid-1];
                    int s=dp[i][j-mid];
                    
                    int move=1+max(b,s);
                    
                    ans=min(ans,move);
                    
                    if(b>s)
                    {
                        high=mid-1;
                        
                    }
                    else low=mid+1;
                    
                    
                    
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][k];
    }
};