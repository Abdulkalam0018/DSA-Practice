class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n=(int)arr.size();
        int total=0;
        for(auto &x:arr)
        {
            total+=x;
            
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
          if(sum+arr[i]==total-sum) return i;
          sum+=arr[i];
          
        }
        return -1;
    }
};