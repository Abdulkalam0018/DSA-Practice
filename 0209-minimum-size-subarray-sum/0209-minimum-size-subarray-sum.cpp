class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int ans=n;
        bool atleast=false;
        int j=0;
        for(int i=0;i<n;i++)
        {
            target-=nums[i];
            while(target<=0)
            {
                atleast=true;
                ans=min(ans,i-j+1);
                target+=nums[j];
                j++;
            }
        }
        return atleast==true?ans:0;
    }
};