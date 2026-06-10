class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n=nums.size();
        vector<int>ans;
        
        stack<int>st;

        st.push(nums[n-1]);

        for(int i=2*n-2;i>=0;i--)
        {
            int p=i%n;
            int a=nums[p];
            while(!st.empty() && a>=st.top())
            {
                st.pop();
            }
            if(i<n)
            {
                if(st.empty())
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(st.top());
                }
            }
            st.push(a);
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};