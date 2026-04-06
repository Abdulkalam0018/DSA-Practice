class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int tar) {
        
        int n=arr.size();
        vector<int>pref(n,INT_MAX),suff(n,INT_MAX);

        map<int,int>mp;

        mp[0]=-1;
        int sum=0;
        int min_val=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(mp.find(sum-tar)!=mp.end())
            {
                int len=i-mp[sum-tar];
                min_val=min(min_val,len);
                pref[i]=min_val;
                
            }
            else
            {
                pref[i]=min_val;
            }
            mp[sum]=i;

        }

        map<int,int>mp1;

        mp1[0]=n;
        sum=0;
        min_val=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            sum+=arr[i];
            if(mp1.find(sum-tar)!=mp1.end())
            {
                int len=mp1[sum-tar]-i;
                min_val=min(min_val,len);
                suff[i]=min_val;
            }
            else
            {
                suff[i]=min_val;
            }
            mp1[sum]=i;
        }

        for(auto &x:pref)
        {
            cout<<x<<" ";
        }
        int i=0;
        int cnt=0;
        int ans=INT_MAX;
        while(i<n-1)
        {
            if(pref[i]!=INT_MAX)
            {
                if(suff[i+1]!=INT_MAX)
                {
                    ans=min(ans,pref[i]+suff[i+1]);
                    cnt=2;
                }
                else
                {
                    if(cnt==2)
                    {
                        return ans;
                    }
                    return -1;
                }
            }
            i++;
        }
        if(ans==INT_MAX)
        return -1;
        return ans;


    }
};