

class Solution {
  public:
    #define ll long long
    ll countSubArrayProductLessThanK(const vector<int>& arr, int n,
                                            ll k) 
    {
        ll ans=0;
        ll i=0;
        ll j=0;
        ll cnt=1;
        while(i<n)
        {
            cnt*=arr[i];
            while(j<=i && cnt>=k)
            {
                cnt/=arr[j];
                j++;
            }
            ans+=(i-j+1);
            i++;
        }
        return ans;
    }
};