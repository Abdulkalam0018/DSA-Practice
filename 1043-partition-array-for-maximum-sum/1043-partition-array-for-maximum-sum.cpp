class Solution {
public:
    int fun(int i,int n,vector<int>& arr, int k,vector<int>& dp)
    {
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int max_e=arr[i];
        int r=INT_MIN;
        for(int ind=i;ind<=min(i+k-1,n);ind++)
        {
            max_e=max(max_e,arr[ind]);
            int p=max_e*(ind-i+1)+fun(ind+1,n,arr,k,dp);
            r=max(r,p);

        }
        return dp[i]=r;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return fun(0,n-1,arr,k,dp);
    }
};