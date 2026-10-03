class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pr, vector<vector<int>>& q) {
        
        int m=q.size();

        vector<vector<int>>adj(n);

        // vector<int>ind(n,0);

        for(auto &x:pr)
        {
            adj[x[0]].push_back(x[1]);
            // ind[x[1]]++;
        }

        queue<int>qu;
        // map<int,vector<int>>mp;
        // int cnt=1;
        // for(auto &x:ind)
        // {

        //     if(x==0)
        //     {
        //         qu.push(x);
        //     }
        // }
        vector<bool>ans;

        for(int i=0;i<m;i++)
        {
            qu.push(q[i][0]);
            bool isok=false;

            while(!qu.empty())
            {
                auto it=qu.front();
                qu.pop();
                for(auto &x:adj[it])
                {
                    if(x==q[i][1])
                    {
                        isok=true;
                        break;
                    }
                    qu.push(x);
                }
                
            }
            ans.push_back(isok);
        }
        return ans;


    }
};