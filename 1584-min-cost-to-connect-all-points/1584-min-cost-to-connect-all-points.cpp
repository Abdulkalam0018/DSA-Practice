class DSU{
    public:
        vector<int>parent,rank;

        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
                rank[i]=0;
            }
        }

        int findp(int node)
        {
            if(parent[node]==node) return node;

            return parent[node]=findp(parent[node]);
        }
        bool unite(int a,int b)
        {
            a=findp(a);
            b=findp(b);

            if(a==b) return false;

            if(rank[a]<rank[b])
            {
                parent[a]=b;
            }
            else if(rank[a]>rank[b])
            {
                parent[b]=a;
            }
            else
            {
                parent[a]=b;
                rank[b]++;
            }
            return true;
        }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        using ii=pair<int,pair<int,int>>;
        vector<ii>v;

        int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                v.push_back({dis,{i,j}});
            }
        }
        sort(v.begin(),v.end());
        
        int m=v.size();
        DSU ds(n);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int a=v[i].second.first;
            int b=v[i].second.second;
            int w=v[i].first;

            if(ds.unite(a,b))
            {
                ans+=w;
            }

        }
        return ans;


    }
};