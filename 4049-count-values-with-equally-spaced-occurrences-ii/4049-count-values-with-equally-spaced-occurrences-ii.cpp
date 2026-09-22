class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(auto &x:mp)
        {
            vector<int>k=x.second;
            int n=k.size();
            if(n>=3)
            {
                int cur=k[1]-k[0];
                bool isok=true;
                for(int i=2;i<n;i++)
                {
                    if(k[i]-k[i-1]!=cur)
                    {
                        isok=false;
                        break;
                    }
                }
                if(isok)
                {
                    ans.push_back(x.first);
                }
            }
        }
        return ans.size();
    }
};