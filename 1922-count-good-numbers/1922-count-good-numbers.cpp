class Solution {
public:
    int countGoodNumbers(long long n) {
        
        using ll=long long;
        ll ans=1;
        if(n%2)
        {
            ans=5;
        }
        ll MOD=1e9+7;
        ll base=20;
        n=n/2;
        while(n>=1)
        {
            if(n&1)
            {
                ans=(1LL*ans*base)%MOD;
            }
            base=(1LL*base*base)%MOD;
            n=n/2;
        }
        return ans;
    }
};