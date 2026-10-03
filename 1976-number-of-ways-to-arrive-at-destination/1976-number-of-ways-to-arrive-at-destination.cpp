class Solution {
public:
    using ll=long long;
    ll MOD=1e9+7;
    ll djs(vector<vector<pair<ll,ll>>>& adj,ll src,ll des)
    {
        vector<ll>dis(des+1,LLONG_MAX);
        vector<ll>nw(des+1,0);
        nw[0]=1;
        dis[src]=0;
        using ii=pair<ll,ll>;
        priority_queue<ii,vector<ii>,greater<>>pq;

        pq.push({0,src});

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            ll wt=it.first;
            ll node=it.second;

            if(wt>dis[node]) continue;

            for(auto &x:adj[node])
            {
                ll nextnode=x.first;
                ll wt1=x.second;

                if(wt+wt1<dis[nextnode])
                {
                    dis[nextnode]=wt+wt1;
                    nw[nextnode]=nw[node]%MOD;
                    pq.push({wt+wt1,nextnode});
                }
                else if(wt+wt1==dis[nextnode])
                {
                    nw[nextnode]=(nw[nextnode]+nw[node])%MOD;
                }
            }
        }
        return nw[des];
        
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<ll,ll>>>adj(n);

        for(auto &x:roads)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }

        ll ans=djs(adj,0,n-1);
        return ans;


    }
};