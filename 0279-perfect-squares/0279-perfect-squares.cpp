class Solution {
public:
    bool istrue=false;
    vector<int>v;
    void perfect()
    {
        if(!istrue)
        {
            istrue=true;
        }
        else return;
        for(int i=1;i*i<=10000;i++)
        {
            int a=i*i;
            v.push_back(a);
        }

    }
    int numSquares(int n) {
        
        perfect();

        int m=v.size();

        // for(auto &x:v)
        // {
        //     cout<<x<<" ";
        // }
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<=n;i++)
        {
            for(auto &x:v)
            {
                if(i-x>=0 && dp[i-x]!=INT_MAX)
                {
                    dp[i]=min(dp[i-x]+1,dp[i]);
                }
            }
        }
        return dp[n];
        
    }
};