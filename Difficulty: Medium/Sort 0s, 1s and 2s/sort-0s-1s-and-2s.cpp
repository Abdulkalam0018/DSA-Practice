class Solution {
  public:
    
    void sort012(vector<int>& arr) {
        // code here
        int i=-1;
        int n=(int)arr.size();
        for(int j=0;j<n;j++)
        {
            if(arr[j]==0)
            {
                i++;
                swap(arr[j],arr[i]);
            }
        }
        for(int j=0;j<n;j++)
        {
            if(arr[j]==1)
            {
                i++;
                swap(arr[j],arr[i]);
            }
        }
        
    }
};