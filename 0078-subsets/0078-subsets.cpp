class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;

        int n=nums.size();

        for(int i=0;i<=((1<<n)-1);i++)
        {
            int j=0;
            vector<int>p;
            int k=i;
            while(k)
            {
                if(k&1)
                {
                    p.push_back(nums[j]);
                }
                k=(k>>1);
                j++;
            }
            ans.push_back(p);

        }
        return ans;
    }
};