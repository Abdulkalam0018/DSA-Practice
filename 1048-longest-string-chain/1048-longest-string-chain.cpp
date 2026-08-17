class Solution {
public:
    int lcs(string a,string b)
    {
        int n=a.size();
        int m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();
        vector<int>dp(n,1);
        sort(words.begin(),words.end(),[](string a,string b){
            return a.size()<b.size();
        });
        int max_ans=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[j].size()+1==words[i].size()){
                    int k=lcs(words[j],words[i]);
                    if(k==words[j].size())
                    {
                        dp[i]=max(dp[i],dp[j]+1);
                        max_ans=max(dp[i],max_ans);
                    }
                }
            }
        }
        return max_ans;

    }
};