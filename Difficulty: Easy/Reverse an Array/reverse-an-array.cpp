class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        
        int n=(int)arr.size();
        for(int i=0;i<n/2;i++)
        {
            int a=arr[i];
            arr[i]=arr[n-i-1];
            arr[n-i-1]=a;
            
        }
    }
};