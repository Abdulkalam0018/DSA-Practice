class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int max_v=0;
        int step=0;
        int n=(int)arr.size();
        int i=0;
        while(i<n)
        {
            if(max_v==i)
            {
                step++;
                max_v=max_v+arr[i];
                i++;
            }
            else
            {
                if(max_v<i) return -1;
                int k=0;
                step++;
                for(int j=i;j<=min(max_v,n-1);j++)
                {
                    k=max(arr[j]+j,k);
                }
                i=max_v+1;
                max_v=k;
            }
            if(max_v>=n-1) return step;
        }
        return step;
    }
};
