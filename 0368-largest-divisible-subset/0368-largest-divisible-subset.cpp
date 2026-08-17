class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>ans;
        vector<int>parent(n,-1);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                    //cout<<nums[j]<<" "<<nums[i]<<" "<<dp[i]<<endl;
                }
            }
        }
        int k=*max_element(dp.begin(),dp.end());
        //cout<<k<<endl;
        int last_element=n-1;
        while(dp[last_element]!=k)
        {
            last_element--;
        }
        while(last_element!=-1)
        {
            ans.push_back(nums[last_element]);
            last_element=parent[last_element];
        }
        //ans.push_back(nums[last_element]);
        reverse(ans.begin(),ans.end());
        // for(auto &x:dp)
        // {
        //     cout<<x<<" ";
        // }
        return ans;



    }
};