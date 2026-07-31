class Solution {
public:

    bool check(vector<int>& piles, int h,int k)
    {
        int cnt=0;
        for(auto &x:piles)
        {
            h-=(x+k-1)/k;
        }
        if(h>=0) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans=-1;
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(piles,h,mid))
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