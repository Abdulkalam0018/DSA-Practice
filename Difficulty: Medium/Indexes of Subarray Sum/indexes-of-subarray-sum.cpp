class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        
        int n=(int)arr.size();
        int sum=0;
        int j=-1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            while(j<i && sum>target)
            {
                j++;
                sum-=arr[j];
            }
            if(sum==target)
            {
                return {j+2,i+1};
            }
        }
        return {-1};
    }
};