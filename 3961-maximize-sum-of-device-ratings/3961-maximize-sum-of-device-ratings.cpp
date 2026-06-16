#define ll long long
class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        ll ans=0;
        for(auto &x:units)
        {
            sort(x.begin(),x.end());
        }
        int a=INT_MAX;
        int b=INT_MAX;
        int m=units[0].size();
        if(m==1)
        {
            for(auto &x:units)
            {
                ans+=x[0];
            }
            return ans;
        }
        for(auto &x:units)
        {
            ans+=x[1];
            b=min(b,x[1]);
            a=min(a,x[0]);
    
        }
        ans+=a;
        ans-=b;
        return ans;
    }
};