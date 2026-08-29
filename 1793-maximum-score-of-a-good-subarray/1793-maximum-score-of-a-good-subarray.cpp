class Solution {
public:
    int maximumScore(vector<int>& a, int k)
    {
        
        int n=a.size();
        int ans = 0 ;
        int l = k ;
        int r = k ;
        int v = a[k] ;
        while(true) {
            ans = max(ans , v * (r - l + 1)) ;
            if(l == 0 && r == n - 1) break ;
            if(l - 1 < 0) {
                v = min(v , a[r + 1]) ;
                r ++ ;
            } else if(r + 1 >= n) {
                v = min(v , a[l - 1]) ;
                l -- ;
            } else if(a[l - 1] <= a[r + 1]) {
                v = min(v , a[r + 1]) ;
                r ++ ;
            } else {
                v = min(v , a[l - 1]) ;
                l -- ;
            }
        }
        return ans;
    }
};