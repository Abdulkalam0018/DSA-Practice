class Solution {
public:
    int largestRectangleArea(vector<int>& h) {

        int n=h.size();
        vector<int>pref(n,-1),suf(n,n);

        stack<int>st;

        st.push(n-1);

        for(int i=n-2;i>=0;i--)
        {
            
            while(!st.empty() && h[st.top()]>=h[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                suf[i]=n;
            }
            else
            {
                suf[i]=st.top();
            }
            st.push(i);

        }
         while (!st.empty()) {
            st.pop();
        }
        st.push(0);
        for(int i=1;i<n;i++)
        {
            
            while(!st.empty() && h[st.top()]>=h[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                pref[i]=-1;
            }
            else
            {
                pref[i]=st.top();
            }
            st.push(i);

        }
        int ans=0;
        // for(auto &x:suf)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto &x:pref)
        // {
        //     cout<<x<<" ";
        // }
        for(int i=0;i<n;i++)
        {
            int dis=suf[i]-pref[i]-1;
            ans=max(dis*h[i],ans);
            //cout<<dis*h[i]<<endl;
        }
        return ans;



    }
};