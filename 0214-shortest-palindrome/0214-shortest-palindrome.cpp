class Solution {
public:
    void buildlps(vector<int>&lps,string s,int n)
    {
        int len=0;

        lps[0]=0;
        int i=1;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        
        int q=s.size();
        string p=s;
        reverse(s.begin(),s.end());

        string k=p+"#"+s;

        int n=k.size();
        vector<int>lps(n,0);

        buildlps(lps,k,n);
        int m=lps[n-1];
        
        string ans="";
        int len=q-m;
        int i=q-1;
        int cnt=0;
        while(cnt<len)
        {
            ans+=p[i];
            i--;
            cnt++;
        }
        return ans+p;
        // aacecaaa#aaacecaa
    }
};