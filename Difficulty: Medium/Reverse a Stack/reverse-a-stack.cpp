class Solution {
  public:
    void recur(stack<int>&st,int a,int sz)
    {
        if(st.size()==sz)
        {
            st.push(a);
            return ;
        }
        int b=st.top();
        st.pop();
        recur(st,a,sz);
        st.push(b);
    }
    void reverseStack(stack<int> &st) {
        // code here
        int n=st.size();
        for(int i=0;i<n-1;i++)
        {
            int a=st.top();
            st.pop();
            recur(st,a,i);
        }
    }
};