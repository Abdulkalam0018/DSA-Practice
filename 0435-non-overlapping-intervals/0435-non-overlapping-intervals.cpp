class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b)
        {
           return a[1]<b[1];
        });

        // for(auto &x:intervals)
        // {
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        int ans=0;

        int n=intervals.size();
        int idx=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<intervals[idx][1])
            {
                ans++;
            }
            else
            {
                idx=i;
            }
           // cout<<idx<<endl;
        }
        return ans;
    }
};