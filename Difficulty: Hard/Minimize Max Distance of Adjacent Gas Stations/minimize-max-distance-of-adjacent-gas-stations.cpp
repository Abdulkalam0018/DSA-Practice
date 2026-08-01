class Solution {
  public: 
    bool fun(vector<int> &st, int k,double dis,int n)
    {
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            int gap=st[i]-st[i-1];
            int required = gap / dis;
            if (gap == required * dis)
                required--;
            cnt+=required;
            if(cnt>k) return false;
        }
        if(cnt<=k) return true;
        return false;
    }
    double minMaxDist(vector<int> &st, int k) {
        
        int n=st.size();
        double low=0;
        double high=st[n-1]-st[0];
        double ans=0;
        double difference=1e-6;
        
        while(difference<high-low)
        {
            double mid=(high+low)/2.0;
            if(fun(st,k,mid,n))
            {
                ans=mid;
                high=mid;
            }
            else low=mid;
            
        }
        return ans;
    }
};