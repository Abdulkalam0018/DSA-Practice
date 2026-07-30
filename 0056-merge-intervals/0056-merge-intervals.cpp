class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end(),[](const vector<int>a,const vector<int>b){
            return a[0]<b[0];
        });

        // for(auto &x:intervals)
        // {
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            vector<int>ch=ans.back();

            if(ch[1]>=intervals[i][0])
            {
                int a=min(intervals[i][0],ch[0]);
                int b=max(intervals[i][1],ch[1]);
                ans.pop_back();
                ans.push_back({a,b});
            }
            else
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
            }

        }
        return ans;
    }
};