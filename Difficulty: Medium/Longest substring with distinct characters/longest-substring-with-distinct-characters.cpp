class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        // g e i f h 
        int n=s.size();
        unordered_map<char,int>mp;
        

        
        int ans=1;
        
        int i=0;
        for(int j=0;j<n;j++)
        {
            mp[s[j]]++;
            
            while(mp[s[j]]>1)
            {
                mp[s[i]]--;
                i++;
            }

            ans=max(ans,j-i+1);
            
        }
        return ans;
        
        
    }
};
