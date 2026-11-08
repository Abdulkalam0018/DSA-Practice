class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;

        vector<int>freq(26,0);
        vector<int>freq1(26,0);
        int cnt=0;

        for(auto &x:s1)
        {
            freq[x-'a']++;
        }
        int i=0;
        int j=n-1;

        for(int k=i;k<=j;k++)
        {
            freq1[s2[k]-'a']++;
        }
        if(freq==freq1) return true;
        i++;
        j++;
        while(j<m)
        {
            freq1[s2[j]-'a']++;
            freq1[s2[i-1]-'a']--;
            if(freq==freq1) return true;    
            i++;
            j++;
        }
        return false;
        
    }
};