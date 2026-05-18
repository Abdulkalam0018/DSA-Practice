class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n=str1.size();
        int m=str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        string s="";

        int i=n;int j=m;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        reverse(s.begin(),s.end());
        string ans="";

        i=0;
        j=0;
        int k=0;
        int p=s.size();

        while(k<p && i<n && j<m)
        {
            if(str1[i]==s[k] && s[k]==str2[j])
            {

                ans+=str1[i];
                i++;
                j++;
                k++;
            }
            else if(s[k]==str1[i])
            {
                ans+=str2[j];
                j++;
            }
            else if(s[k]==str2[j])
            {
                ans+=str1[i];
                i++;
            }
            else
            {
                ans+=str1[i];
                ans+=str2[j];
                i++;
                j++;
            }
        }
        while(i<n)
        {
            ans+=str1[i];
            i++;
        }
        while(j<m)
        {
            ans+=str2[j];
            j++;
        }
        return ans;
    }
};