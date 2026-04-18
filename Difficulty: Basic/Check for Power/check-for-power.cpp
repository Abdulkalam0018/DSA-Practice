class Solution {
  public:
    bool isPower(int x, int y) {
        if (y == 1) return true;      
        if (x == 1) return y == 1;    
        if (x == 0) return false;     
        
        while (y % x == 0) {
            y /= x;
        }
        
        return y == 1;
    }
};