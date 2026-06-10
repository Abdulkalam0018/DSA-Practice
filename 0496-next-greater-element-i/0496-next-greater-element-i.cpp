class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int>mp;
        int n=nums2.size();
        mp[nums2[n-1]]=-1;

        stack<int>st;
        st.push(nums2[n-1]);

        for(int i=n-2;i>=0;i--)
        {
            int a=nums2[i];
            
            while(!st.empty() && st.top()<=a)
            {
                st.pop();
            }
            if(st.empty())
            {
                mp[nums2[i]]=-1;
            }
            else
            {
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);

        }
        vector<int>ans;
        for(auto &x:nums1)
        {
            ans.push_back(mp[x]);
        }
        return ans;
    }
};