class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int ans=0;
        int cnt=0;
        unordered_map<int,int>mp;

        for(int j=0;j<n;j++)
        {
            if(mp.find(fruits[j])!=mp.end())
            {
                mp[fruits[j]]++;
            }
            else
            {
                cnt++;
                mp[fruits[j]]++;
            }
            while(cnt>2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                {
                    mp.erase(fruits[i]);
                    cnt--;
                }
                i++;
            }
            ans=max(ans,j-i+1);

        }
        return ans;
    }
};