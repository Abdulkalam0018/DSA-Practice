class Solution {
public:
    bool isok(vector<int>& piles, int h , int lim)
    {
        int actualh=0;
        for(auto &x:piles)
        {
            actualh+=(x+lim-1)/lim;
            if(actualh>h) return false;
        }
        if(actualh<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(isok(piles,h,mid))
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