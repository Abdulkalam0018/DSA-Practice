class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        set<int>st;

        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b)
        {
            return a[1]<b[1];
        });

        int ans=0;
        int n=points.size();

        for(int i=0;i<n;i++)
        {
            int a=points[i][0];
            auto it=st.lower_bound(a);

            if(it==st.end())
            {
                ans++;
                st.insert(points[i][1]);
            }

        }
        return ans;

    }
};