class Solution {
public:
    bool isok(vector<int>& w, int days , int lim)
    {
        int adays=1;
        int cur=0;
        for(auto &x:w)
        {
            cur+=x;
            if(x>lim) return false;
            if(cur>lim)
            {
                adays++;
                cur=x;
            }
            if(adays>days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& w, int days) {
        
        int low=1;
        int high=accumulate(w.begin(),w.end(),0LL);
        int ans=high;   
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(isok(w,days,mid))
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