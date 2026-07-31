class Solution {
public:
    bool check(vector<int>& weights, int days, int limit)
    {
        int sum=0;
        int cnt=1;
        for(auto &x:weights)
        {
            if(x>limit) return false;
            if(sum+x>limit)
            {
                cnt++;
                sum=x;
            }
            else
            {
                sum+=x;
            }
        }
        
        if(cnt<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int ans=0;
        int low=1;
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(weights,days,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};