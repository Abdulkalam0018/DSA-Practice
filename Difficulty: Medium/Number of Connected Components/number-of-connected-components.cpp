class Solution {
  public:
    void dfs(vector<vector<int>>&graph ,vector<int>&vis ,int i)
    {
        vis[i]=0;
        for(auto &x:graph[i])
        {
            if(vis[x])
                dfs(graph,vis,x);
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>graph(V);
        
        for(auto &x:edges)
        {

                graph[x[0]].push_back(x[1]);
                graph[x[1]].push_back(x[0]);
            
        }
        
        int cnt=0;
        
        vector<int>vis(V,1);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i])
            {
                cnt++;
                dfs(graph,vis,i);
            }
        }
        return cnt;
    }
};