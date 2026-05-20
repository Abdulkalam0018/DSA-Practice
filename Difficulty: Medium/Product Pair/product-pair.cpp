class Solution {
  public:
   #define ll long long
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        
        map<ll,ll>mp;
        for(auto &x:arr)
        {
           mp[x]++;
        }
        
        for(auto &x:arr)
        {
            if(target%x==0)
            {
                long long k=(1LL*target)/(1LL*x);
                if(k!=x)
                {
                    if(mp.count(k)) return true;
                }
                else
                {
                    if(mp[k]>=2) return true;
                }
                
            }
        }
        return false;
    }
};