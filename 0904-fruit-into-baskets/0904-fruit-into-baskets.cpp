class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        vector<int>mp(fruits.size(),0);
        int cnt=0;
        int ans=0;

        int n=fruits.size();

        int j=0;
        for(int i=0;i<n;i++)
        {
            mp[fruits[i]]++;
            if(mp[fruits[i]]==1) cnt++;

            while(cnt>2)
            {
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0) cnt--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};