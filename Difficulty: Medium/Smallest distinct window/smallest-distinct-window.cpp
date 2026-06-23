class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set<char>st;
        for(auto &x:str)
        {
            if(st.empty())
            {
                st.insert({x});
            }
            else 
            {
                if(!st.count(x))
                {
                    st.insert({x});
                }
            }
        }
        
        int tar=st.size();
        //cout<<tar<<endl;
        vector<int>freq(26,0);
        
        int n=str.size();
        int cnt=0;
        
        int i=0;
        int ans=INT_MAX;
        
        while(i<n)
        {
            if(freq[str[i]-'a']==0)
            {
                cnt++;
                freq[str[i]-'a']=1;
            }
            if(cnt==tar)
            {
                
                int j=i;
                vector<int>freq1(26,0);
                int cnt1=0;
                while(j>=0)
                {
                    if(freq1[str[j]-'a']==0)
                    {
                        cnt1++;
                        freq1[str[j]-'a']=1;
                    }
                    if(cnt1==tar)
                    {
                        ans=min(ans,i-j+1);
                        break;
                    }
                    j--;
                }
                //cout<<i<<" "<<ans<<endl;
                i=j+1;
                cnt=0;
                vector<int>k(26,0);
                freq=k;
                continue;
            }
            i++;
            
        }
        return ans;
    }
};