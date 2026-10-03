class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int>v;
        v=nums;
        v.insert(v.end(),nums.begin(),nums.end());

        int m=nums.size();
        int n=v.size();
        stack<int>st;
        vector<int>ans(m,-1);
        // 1 2 1 1 2 1
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && v[st.top()]<=v[i])
            {
                st.pop();
            }

            if(i<m)
            {
                if(st.empty())
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=v[st.top()];
                }
            }
            st.push(i);
        }
        return ans;

    }
};