class Solution {
public:
    int maximumScore(vector<int>& nums, int k)
    {
        
        int n=nums.size();
        vector<int>pref(n,-1),suf(n,n);

        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                pref[i]=st.top();
            }
            else
            {
                pref[i]=-1;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                suf[i]=st.top();
            }
            else 
            {
                suf[i]=n;
            }
            st.push(i);
        }

        for(auto &x:pref)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto &x:suf)
        {
            cout<<x<<" ";
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int a=pref[i]+1;
            int b=suf[i]-1;
            if(k>=a && k<=b)
            {
                int dis=b-a+1;
                int c=dis*nums[i];
                ans=max(ans,c);
            }
        }
        return ans;
    }
};