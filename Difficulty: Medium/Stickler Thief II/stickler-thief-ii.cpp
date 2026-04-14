class Solution {
  public:
    int maxValue(vector<int>& arr) {
        // code here
        int n=(int)arr.size();
        
        vector<int>dp1(n+1,0),dp2(n+1,0);
        
        for(int i=1;i<n;i++)
        {
            if(i==1)
            {
                dp1[1]=arr[i-1];
            }
            else
            {
                dp1[i]=max(dp1[i-1],arr[i-1]+dp1[i-2]);
            }

        }
        for(int i=2;i<=n;i++)
        {
            if(i==2)
            {
                dp2[2]=arr[i-1];
            }
            else
            {
                dp2[i]=max(dp2[i-1],arr[i-1]+dp2[i-2]);
            }
        }
        return max(dp1[n-1],dp2[n]);
    }
};
