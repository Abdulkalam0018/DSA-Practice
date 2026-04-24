class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int a=arr[0];
        int n=(int)arr.size();
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>=a)
            {
                cnt++;
                a=arr[i];
            }
        }
        return cnt;
    }
};