class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& inter)
    {
        int n=inter.size();
        vector<int>v;
        for(auto &x:inter)
        {
            v.push_back(x[0]);
        }
        sort(v.begin(),v.end());
        sort(inter.begin(),inter.end(),[](vector<int>&a,vector<int>&b)
        {
            return a[1]<b[1];
        });
        using ll =long long;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int a=inter[i][1];
            auto it=upper_bound(v.begin(),v.end(),a);
            if(it!=v.begin())
            {
                it--;
                auto dis=distance(v.begin(),it);
                ans+=dis-i;
            }

        }
        return ans;
    }
};