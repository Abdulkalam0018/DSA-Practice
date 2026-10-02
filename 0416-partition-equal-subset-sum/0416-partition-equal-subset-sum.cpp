class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum=accumulate(nums.begin(),nums.end(),0LL);
        int n=nums.size();

        if(sum%2!=0) return false;
        int k=sum/2;



        vector<int>dp(k+1,0);
        dp[0]=1;

        for(auto &x:nums)
        {
            for(int i=k;i>=0;i--)
            {
                if(i-x>=0 && dp[i-x]==1)
                {
                    dp[i]=1;
                }
            }
        }
        if(dp[k]==1) return true;
        return false;
    }
};