class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) return 0;
        vector<int>dis(1001,-1);
        
        dis[start]=0;
        
        queue<int>q;
        
        q.push(start);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(auto &x:arr)
            {
                int a=(1LL*it*x)%1000;
                if(a==end) return dis[it]+1;
                
                
                if(dis[a]==-1)
                {
                    dis[a]=1+dis[it];
                    q.push(a);
                }
                
            }

        }
        return -1;
    }
};