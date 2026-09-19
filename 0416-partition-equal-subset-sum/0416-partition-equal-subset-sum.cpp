class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=accumulate(nums.begin(),nums.end(),0LL);
        if(sum%2!=0) return false;

        int p=sum/2;
        vector<bool>dp(p+1,false);
        dp[0]=true;

        for(auto &x:nums)
        {
            if(x>p) return false;
            for(int j=p;j>=0 ;j--)
            {
                if(j-x>=0)
                {
                    dp[j]=(dp[j]|dp[j-x]);
                }
            }
        } 
        return dp[p];
    }
};