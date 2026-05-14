class Solution {
public:
    #define ll long long
    const ll INF = 1e18;

    vector<ll> dijasktra(int src, int n, vector<vector<pair<int,ll>>>& edges)
    {
        vector<ll> dis(n, INF);
        dis[src] = 0;

        using state = pair<ll,int>;
        priority_queue<state, vector<state>, greater<state>> pq;

        pq.push({0, src});

        while(!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dis[u]) continue;

            for(auto &x : edges[u])
            {
                int v = x.first;
                ll w = x.second;

                if(dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        return dis;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) 
    {
        vector<ll> ans(n);

        for(int i = 0; i < n; i++)
        {
            ans[i] = prices[i];
        }

        vector<vector<pair<int,ll>>> edges1(n);
        vector<vector<pair<int,ll>>> edges2(n);

        for(auto &x : roads)
        {
            int a = x[0];
            int b = x[1];
            ll c = x[2];
            ll d = x[3];

            ll tax = c * d;

            edges1[a].push_back({b, c});
            edges1[b].push_back({a, c});

            edges2[a].push_back({b, tax});
            edges2[b].push_back({a, tax});
        }

        for(int i = 0; i < n; i++)
        {
            vector<ll> dis1 = dijasktra(i, n, edges1);
            vector<ll> dis2 = dijasktra(i, n, edges2);

            ll p = prices[i];

            for(int j = 0; j < n; j++)
            {
                if(i != j && dis1[j] != INF && dis2[j] != INF)
                {
                    ll k = dis1[j] + dis2[j] + prices[j];
                    p = min(p, k);
                }
            }

            ans[i] = p;
        }

        vector<int> finalAns(n);
        for(int i = 0; i < n; i++)
        {
            finalAns[i] = (int)ans[i];
        }

        return finalAns;
    }
};