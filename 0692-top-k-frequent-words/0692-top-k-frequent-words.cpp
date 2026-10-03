class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;

        for(auto &x:words)
        {
            mp[x]++;
        }
        vector<string>ans;

        map<int,set<string>>st;
        for(auto &x:mp)
        {
            st[x.second].insert(x.first);
        }
        // for(auto &x:st)
        // {
        //     for(auto &y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        auto it=st.end();
        it--;

        while(k>0)  
        {
            set<string>st1=it->second;
            int m=st1.size();
            if(m<=k)
            {
                k-=m;
                for(auto &x:st1)
                {
                    ans.push_back(x);
                }
            }
            else
            {
                for(auto &x:st1)
                {
                    if(k==0) break;
                    ans.push_back(x);
                    k--;
                }
            }
            it--;


        }
        return ans;
    }
};