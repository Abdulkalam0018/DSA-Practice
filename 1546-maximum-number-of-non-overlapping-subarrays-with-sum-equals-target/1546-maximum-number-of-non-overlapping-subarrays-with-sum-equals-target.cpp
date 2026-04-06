class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int tar) {

        unordered_set<int>st;
        int cnt=0;
        int sum=0;
        for(auto &x:nums)
        {
            sum+=x;
            if(sum==tar)
            {
                 cnt++;
                 st.clear();
                 sum=0;
            }
            else if(st.count(sum-tar))
            {
                cnt++;
                st.clear();
                sum=0;
            }

            //cout<<x<<" "<<cnt<<endl;
            st.insert({sum});
        }
        return cnt;

    }
};