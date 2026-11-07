class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m) return "";

        int cnt=0;
        vector<int>freq(256,0);

        for(auto &x:t)
        {
            freq[x]++;
            if(freq[x]==1) cnt++;
        }
        //cout<<cnt<<endl;
        int len=n;
        int idx=0;
        int j=0;
        bool atleast=false;
        for(int i=0;i<n;i++)
        {
            freq[s[i]]--;
            if(freq[s[i]]==0) cnt--;
            while(cnt==0)
            {
                atleast=true;
                int a=i-j+1;
                if(a<len)
                {
                    len=a;
                    idx=j;
                }
                freq[s[j]]++;
                if(freq[s[j]]>0) cnt++;
                j++;
                
            }
        }
        string ans=s.substr(idx,len);
        return atleast==true?ans:"";
    }
};