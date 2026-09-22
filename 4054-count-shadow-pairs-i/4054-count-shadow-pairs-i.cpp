class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        // 3
        // 1 4 1 5
        using ll=long long;
        stack<ll>st;
        unordered_map<int,int>freq;
       
        ll ans=0;
        for(auto &x:nums)
        {
            if(st.empty())
            {
                st.push(x);
                freq[x]++;
                continue;
            }

            while(!st.empty() && st.top()>x)
            {
                freq[st.top()]--;
                st.pop();
            }
            if(!st.empty() && st.top()==x)
            {
                ans+=st.size()-freq[x];
            }
            else
               ans+=st.size();
            st.push(x);
            freq[x]++;
        }
        return ans;
    }
};