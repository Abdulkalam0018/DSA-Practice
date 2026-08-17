class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int>v;

        for(int i=0;i<n;i++)
        {
            if(v.size()>0 && v.back()==nums[i]) continue;
            auto it=lower_bound(v.begin(),v.end(),nums[i]);
            if(it==v.end())
            {
                v.push_back(nums[i]);
            }
            else if(*it==nums[i]) continue;
            else{
                *it=nums[i];
            }
        }
        return v.size();
    }
};