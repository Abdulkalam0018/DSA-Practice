class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int max_ele=*max_element(nums.begin(),nums.end());
        vector<int>ans(max_ele+1,0);

        for(auto &x:nums)
        {
            ans[x]+=x;
        }
        if(max_ele==1) return ans[1];
        if(max_ele==2) return max(ans[1],ans[2]);
        vector<int>dp(max_ele+1,0);
        dp[0]=ans[0];
        dp[1]=ans[1];
        dp[2]=max(ans[1],ans[2]);

        for(int i=3;i<=max_ele;i++)
        {
            dp[i]=max(ans[i]+dp[i-2],dp[i-1]);
        }
        return dp[max_ele];

    }
};