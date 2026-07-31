class Solution {
public:
    bool fun(vector<int>& bloom, int m, int k,int lim)
    {
        int cnt=0;
        int sum=0;

        for(auto &x:bloom)
        {
            if(x<=lim)
            {
                sum++;
                if(sum==k)
                {
                    cnt++;
                    sum=0;
                }

            }
            else
            {
                sum=0;
            }
        }
        if(cnt>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        
        int low=1;
        int high=*max_element(bloom.begin(),bloom.end());
        int day=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(fun(bloom,m,k,mid))
            {
                day=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return day;
    }
};