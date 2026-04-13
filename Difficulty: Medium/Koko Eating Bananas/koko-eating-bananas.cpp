class Solution {
  public:
    bool check(vector<int>& arr,int mid,int k)
    {
        int cnt=0;
        for(auto &x:arr)
        {
            cnt+=(x+mid-1)/mid;
        }
        if(cnt<=k) return true;
        return false;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low=1;
        int high=1e6;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(arr,mid,k))
            {
                ans=min(ans,mid);
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