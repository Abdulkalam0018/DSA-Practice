class Solution {
public:
    bool fun(int i,int j,string &s,string &p,int n,int m,vector<vector<int>> &dp)
    {
        if(i==n)
        {
            for(int k=j;k<m;k++)
            {
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(s[i]==p[j])
        {
            ans|= fun(i+1,j+1,s,p,n,m,dp);
        }
        if(p[j]=='?')
        {
            ans|= fun(i+1,j+1,s,p,n,m,dp);
        }
        if(p[j]=='*')
        {
            ans|=fun(i+1,j+1,s,p,n,m,dp);
            ans|=fun(i+1,j,s,p,n,m,dp);
            ans|=fun(i,j+1,s,p,n,m,dp);
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        
        int n=s.size();
        int m=p.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(0,0,s,p,n,m,dp);
    }
};