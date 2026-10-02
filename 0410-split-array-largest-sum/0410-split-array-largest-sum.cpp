class Solution {
public:
    bool isok(vector<int>& nums, int k , int lim)
    {
        int cur=0;
        int split=1;
        for(auto &x:nums)
        {
            if(x>lim) return false;
            cur+=x;
            if(cur>lim)
            {
                cur=x;
                split++;
            }
            if(split>k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int low=*min_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0LL);

        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(isok(nums,k,mid))
            {
                ans=mid;
                high=mid-1;

            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};