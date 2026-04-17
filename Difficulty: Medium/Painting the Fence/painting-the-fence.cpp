class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        int same=0;
        int diff=k;
        int total=k;
        for(int i=0;i<n-1;i++)
        {
            total=diff*k+same*(k-1);
            same=diff;
            diff=total-same;
        }
        return total;
    }
};