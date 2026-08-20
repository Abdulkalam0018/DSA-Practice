class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp1(n+1,0),dp2(n+1,0);

        dp1[1]=nums[0];
        dp1[2]=max(nums[0],nums[1]);

        for(int i=3;i<n;i++)
        {
            dp1[i]=max(nums[i-1]+dp1[i-2],dp1[i-1]);
        }

        if(n==3)
        {
            int ans=max({nums[0],nums[1],nums[2]});
            return ans;
        }
        dp2[2]=nums[1];

        dp2[3]=max(nums[1],nums[2]);


        for(int i=4;i<=n;i++)
        {
            dp2[i]=max(nums[i-1]+dp2[i-2],dp2[i-1]);
        }
        return max(dp1[n-1],dp2[n]);
    }
};