#define ll long long
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n=nums.size();

        ll ans=0;

        for(int i=0;i<n;i++)
        {
            ll a=nums[i];
            ll b=nums[i];

            for(int j=i;j<n;j++)
            {
                if(nums[j]<a)
                {
                    a=nums[j];
                }
                if(nums[j]>b)
                {
                    b=nums[j];
                }
                ans+=b-a;
            }
        }
        return ans;
    }
};