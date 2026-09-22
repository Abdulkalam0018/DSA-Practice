class Solution {
public:

    int minDays(int n)
    {
        // using ii=pair<int,pair<int,int>>;
        // queue<ii>q;

        // q.push({0,{0,0}});
        // while(!q.empty())
        // {
        //     auto it=q.front();
        //     q.pop();
        //     int a=it.first;
        //     int b=it.second.first;
        //     int c=it.second.second;
        //     if(a==n) return b;
        //     if(a>n) continue;
        //     int d=a+c+1;
        //     q.push({d,{b+1,c+1}});
        //     q.push({a,{b+1,0}});
        // }
        // return 0;
        vector<int>dp(n+1,100005);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;;j++)
            {
                if(i-j*(j+1)/2>=0)
                   dp[i]=min(dp[i],dp[i-j*(j+1)/2]+j+1);
                else break;
            }
        }
        return dp[n]-1;
    }
};