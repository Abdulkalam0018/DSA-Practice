class Solution {
public:
    using ll=long long;
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        vector<int>pref(n,0);

        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=nums[i]+pref[i-1];
        }

        for(auto &x:pref)
        {
            cout<<x<<" ";
        }
        unordered_map<int,int>mp;
        mp[0]=-1;
        int ans=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int a=pref[n-1]-pref[i];
            int b=x-a;
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
            }
            if(mp.find(b)!=mp.end())
            {
                ans=min(ans,n-(i-mp[b]));
            }

        }
        return ans==INT_MAX?-1:ans;

    }
};