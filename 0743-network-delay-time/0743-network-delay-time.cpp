class Solution {
public:
    int djs(vector<vector<pair<int,int>>>& adj, int n, int k) {
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        
        using ii = pair<int, int>;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [w, nd] = pq.top();
            pq.pop();
            
            if (w > dis[nd]) continue;

            for (auto& [nxt, weight] : adj[nd]) {
                if (w + weight < dis[nxt]) {
                    dis[nxt] = w + weight;
                    pq.push({dis[nxt], nxt});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (const auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        return djs(adj, n, k);
    }
};