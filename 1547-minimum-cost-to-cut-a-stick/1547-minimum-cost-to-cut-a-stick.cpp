class Solution {
public:

    int fun(int i,int j,vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mink=INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            int k=cuts[j+1]-cuts[i-1]+fun(i,ind-1,cuts,dp)+fun(ind+1,j,cuts,dp);
            mink=min(mink,k);
        }
        return dp[i][j]=mink;
    }
    int minCost(int n, vector<int>& cuts) {
        
        int m=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return fun(1,m,cuts,dp);

    }
};