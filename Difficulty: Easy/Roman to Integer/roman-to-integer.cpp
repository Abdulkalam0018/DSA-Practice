class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int>mp1;
        mp1['I']=1;
        mp1['V']=5;
        mp1['X']=10;
        mp1['L']=50;
        mp1['C']=100;
        mp1['D']=500;
        mp1['M']=1000;
        int ans=0;
        int n=(int)s.size();
        int i=0;
        while(i<n)
        {
            //cout<<ans<<endl;
            if(i<n-1)
            {
                if(mp1[s[i]]<mp1[s[i+1]])
                {
                    ans+=mp1[s[i+1]]-mp1[s[i]];
                    i+=2;
                }
                else
                {
                    ans+=mp1[s[i]];
                    i+=1;
                }
            }
            else
            {
                ans+=mp1[s[i]];
                i++;
            }
        }
        return ans;
    }
};