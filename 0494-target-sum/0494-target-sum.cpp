class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=accumulate(nums.begin(),nums.end(),0LL);

        if(abs(target)>sum || (sum+target)%2) return 0;

        int tar=(sum+target)/2;
        
        vector<int>dp(tar+1,0);
        dp[0]=1;
        for(auto &x:nums)
        {
            for(int i=tar;i>=0;i--)
            {
                if(i-x>=0 && dp[i-x]>0){
                   dp[i]=dp[i]+dp[i-x];
                }
            }
            //cout<<dp[1]<<endl;
        }
        //cout<<tar<<endl;
        //2->3
        //1->4
        //3->2
        //4->1
        return dp[tar];

    }
};