class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        
        int n=arr.size();
        vector<int>ans(n,-1);
        
        stack<int>st;
        st.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            int a=arr[i];
            while(!st.empty() && a<=st.top())
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(a);
        }
        return ans;
        
        
        
    }
};