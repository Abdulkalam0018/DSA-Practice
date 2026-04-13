class Solution {
  public:
    bool check1(int mid,vector<int> &arr,int k)
    {
        int cnt=0;
        int sum=0;
        for(auto &x:arr)
        {
            if(x>mid) return false;
            if(sum+x>mid)
            {
                sum=x;
                cnt++;
            }
            else
            {
                sum+=x;
            }
            
        }
        //cout<<cnt<<endl;
        if(cnt+1<=k) return true;
        return false;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k) return -1;
        int low=*min_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        
        int ans=high;
        //cout<<low<<""<<high<<endl;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check1(mid,arr,k))
            {
                //cout<<mid<<endl;
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