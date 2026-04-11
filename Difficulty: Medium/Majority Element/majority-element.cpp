class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        
        int n=(int)arr.size();
        int cnt=1;
        int ele=arr[0];
        for(int i=1;i<n;i++)
        {
            if(cnt==0)
            {
                ele=arr[i];
                cnt++;
            }
            else
            {
                if(ele==arr[i])
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
            }
        }
        int k=0;
        if(cnt==0) return -1;
        for(auto &x:arr)
        {
            if(ele==x) k++;
            
        }
        if(k>n/2) return ele;
        return -1;
        
    }
};