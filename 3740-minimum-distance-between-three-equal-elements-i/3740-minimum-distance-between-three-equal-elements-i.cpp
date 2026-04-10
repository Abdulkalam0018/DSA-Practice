class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n=(int)nums.size();
        int best=INT_MAX;
        for(int i=1;i<n-1;i++)
        {
            int j=i-1;
            int k=i+1;
            while(j>=0 && nums[j]!=nums[i])
            {
                j--;
            }
            if(j<0) continue;
            while(k<n && nums[k]!=nums[i])
            {
                k++;
            }
            if(k>=n) continue;
            else
            {
                int ans=abs(i-j)+abs(i-k)+abs(j-k);
                best=min(ans,best);
            }

        }
        return best==INT_MAX?-1:best;
    }
};