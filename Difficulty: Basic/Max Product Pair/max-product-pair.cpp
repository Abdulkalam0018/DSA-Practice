class Solution {
  public:
    int maxProduct(vector<int>& arr) {
        // code here

        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int a=arr[n-1];
        int b=arr[n-2];
        long long ans=1LL*a*b;
        return ans;
        
    }
};