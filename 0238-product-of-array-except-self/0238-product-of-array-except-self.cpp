class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int cnt=0;
        int pr=1;
        for(auto &x:nums)
        {
            if(x==0)
            {
                cnt++;
            }
            else
            {
                pr*=x;
            }
        }
        int n=nums.size();
        vector<int>ans(n,0);
        if(cnt>=2)
        {
            return ans;
        }
        if(cnt==1)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    ans[i]=pr;
                }
            }
            return ans;
        }
            for(int i=0;i<n;i++)
            {

                ans[i]=pr/nums[i];
                
            }
            return ans;



    }
};