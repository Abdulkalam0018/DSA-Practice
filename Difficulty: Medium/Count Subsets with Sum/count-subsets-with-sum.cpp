class Solution {
  public:
    int perfectSum(vector<int>& arr, int tar) {
        // code here
        int n=arr.size();
        vector<int>dp(tar+1,0);
        dp[0]=1;
        for(auto &x:arr)
        {
            for(int i=tar;i>=0;i--)
            {
                if(i-x>=0)
                {
                    dp[i]+=dp[i-x];
                }
            }
        }
        // for(auto &x:dp)
        // {
        //     cout<<x<<" ";
        // }
        return dp[tar];
    }
};