class Solution {
public:
    int bestClosingTime(string cs) {
        
        int n=cs.size();

        vector<int>prefix(n,0),suffix(n,0);

        prefix[0]=(cs[0]=='N'?1:0);
        for(int i=1;i<n;i++)
        {
            prefix[i]=(prefix[i-1]+(cs[i]=='N'?1:0));
            //cout<<prefix[i]<<endl;
        }
        suffix[n-1]=(cs[n-1]=='Y'?1:0);
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=(suffix[i+1]+(cs[i]=='Y'?1:0));
        }
        int ans=n;
        // for(auto &x:prefix)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto &x:suffix)
        // {
        //     cout<<x<<" ";
        // }
        int ans2=0;
        for(int i=0;i<=n;i++)
        {
            int k=0;
            if(i==0)
            {
                k=suffix[i];
            }
            else if(i==n)
            {
                k=prefix[i-1];
            }
            else
            {
                k=prefix[i-1]+suffix[i];
            }
            //k-=(cs[i]=='N'?1:0);
            //cout<<k<<endl;
            if(k<ans)
            {
                ans2=i;
                ans=k;
            }
        }
        return ans2;
    }
};