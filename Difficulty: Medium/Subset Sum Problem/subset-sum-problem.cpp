class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<bool>dp(sum+1,false);
        dp[0]=true;
        
        for(auto &x:arr)
        {
            if(sum<x) continue;
            for(int i=sum;i>=0;i--)
            {
                if(i-x>=0)
                {
                    dp[i]= (dp[i]|dp[i-x]);
                }
            }
        }
        
        return dp[sum];
    }
    // 3 7 4 9 
    // 
};