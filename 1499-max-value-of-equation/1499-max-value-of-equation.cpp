class SparseTable{
    vector<vector<int>>s;
    public:
        SparseTable(vector<int>&a)
        {
            int n=a.size();
            if(n==0) return ;

            int log=32-__builtin_clz(n);
            s.assign(log,vector<int>(n));
            s[0]=a;
            for(int p=1;p<log;p++)
            {
                for(int i=0;i+(1<<p)<=n;i++)
                {
                    s[p][i]=max(s[p-1][i],s[p-1][i+(1<<(p-1))]);
                }
            }
        }
        int query(int l,int r)
        {
            int p=31-__builtin_clz(r-l+1);

            return max(s[p][l],s[p][r-(1<<p)+1]);
        }
};

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k)
    {
        
        
        int n=points.size();
        vector<int>a;
        vector<int>dif;
        vector<int>st;
        for(auto &x:points)
        {
            a.push_back(x[0]+x[1]);
            dif.push_back(x[1]-x[0]);
            st.push_back(x[0]);
        }
        SparseTable sp(a);
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int a=points[i][0]+k;
            auto it=upper_bound(st.begin(),st.end(),a)-st.begin()-1;

            if(it<=i) continue;

            int ax=sp.query(i+1,it);
            ans=max(ans,ax+dif[i]);

        }
        return ans;
    }
};