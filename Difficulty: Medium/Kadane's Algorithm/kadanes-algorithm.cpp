class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int best=arr[0];
        int n=(int)arr.size();
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=max(arr[i],sum+arr[i]);
            best=max(best,sum);
        }
        return best;
    }
};