class DSU{
    public:
        vector<int>parent;
        vector<int>rank;

        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n);

            for(int i=0;i<n;i++)
            {
                rank[i]=0;
                parent[i]=i;
            }
        }

        int findp(int node)
        {
            if(node==parent[node]) return node;
            return parent[node]=findp(parent[node]);
        }
        void unite(int a,int b)
        {
            a=findp(a);
            b=findp(b);
            if(a==b) return ;

            if(rank[a]>rank[b])
            {
                parent[b]=a;
            }
            else if(rank[a]<rank[b])
            {
                parent[a]=b;
            }
            else
            {
                parent[a]=b;
                rank[b]++;
            }
        }
        int components()
        {
            set<int>st;
            for(auto &x:parent)
            {
                int a=findp(x);
                st.insert(a);
            }
            return st.size();
        }
};
class Solution {
public:
    // vector<int>dir1={0,0,-1,1};
    // vector<int>dir2={-1,1,0,0};
    // bool isok(int i,int j,int n,int m)
    // {
    //     return (i>=0 && i<n && j>=0 && j<m);
    // }
    // void dfs(vector<vector<int>>& isConnected,int i,int j,vector<vector<int>>& vis,int n,int m)
    // {
    //     if(i>=n || i<0 || j<0 || j>=m) return ;
    //     if(vis[i][j]==1) return ;

    //     vis[i][j]=1;

    //     for(int k=0;k<4;k++)
    //     {
    //         int x=dir1[k]+i;
    //         int y=dir2[k]+j;

    //         if(isok(x,y,n,m) && vis[x][y]==0 && isConnected[x][y]==1)
    //         {
    //             dfs(isConnected,x,y,vis,n,m);
    //         }
    //     }


    // }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // 1 0 0 1
        // 0 1 1 0 
        // 0 1 1 1
        // 1 0 1 1

        int ans=0;

        int n=isConnected.size();
        int m=isConnected[0].size();

        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }

        }

        DSU ds(n);


        for(int i=0;i<n;i++)
        {
            for(auto &x:adj[i])
            {
                ds.unite(x,i);
            }
        }
        ans=ds.components();
        return ans;
        
    }
};