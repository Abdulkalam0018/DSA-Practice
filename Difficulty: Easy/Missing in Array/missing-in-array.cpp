class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        
        int n=(int)arr.size();
        int xor1=0;
        int xor2=0;
        for(int i=1;i<=n+1;i++) xor1^=i;
        for(auto &x:arr) xor2^=x;
        return xor2^xor1;
    }
};