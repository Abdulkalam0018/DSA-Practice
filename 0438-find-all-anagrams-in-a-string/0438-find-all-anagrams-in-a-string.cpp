class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>freq1(26,0),freq2(26,0);
        int n=s.size();
        int m=p.size();

        vector<int>ans;
        if(n<m) return ans;

        for(auto &x:p)
        {
            freq1[x-'a']++;

        }
        for(int i=0;i<m;i++)
        {
            freq2[s[i]-'a']++;
        }
        if(freq1==freq2) ans.push_back(0);

        int j=0;
        for(int i=m;i<n;i++)
        {
            freq2[s[j]-'a']--;
            freq2[s[i]-'a']++;
            j++;
            if(freq2==freq1) ans.push_back(j);
        }
        return ans;

        
    }
};