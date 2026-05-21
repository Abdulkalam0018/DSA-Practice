class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;
        while(n)
        {
            if((n&1)==0) return false;
            n=(n>>1);
        }
        return true;
    }
};