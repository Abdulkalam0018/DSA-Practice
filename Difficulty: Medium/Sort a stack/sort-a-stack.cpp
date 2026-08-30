class Solution {
  public:
    void recur(stack<int>& st)
    {
        if(st.size()==2)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(a<b)
            {
                st.push(a);
                st.push(b);
            }
            else
            {
                st.push(b);
                st.push(a);
            }
            return ;
        }
        int a=st.top();
        st.pop();
        recur(st);
            int b=st.top();
            st.pop();
            if(a<b)
            {
                st.push(a);
                st.push(b);
            }
            else
            {
                st.push(b);
                st.push(a);
            }
            return ;
        
    }
    void sortStack(stack<int> &st) {
        // code here
        int n=st.size();
        if(n==1) return ;
        for(int i=0;i<n;i++)
        {
            recur(st);
        }
    }
};
