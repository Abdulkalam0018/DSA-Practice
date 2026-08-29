class Solution {
public:
    bool fun(int i,unordered_map<int,int>& mp,unordered_map<int,int>&freq)
    {
        


        for(auto &x:freq)
        {
            if(mp.find(x.first)==mp.end() || mp[x.first]!=x.second)
            {
                return false;
            }
        }
        return true;
    }
    int maxChunksToSorted(vector<int>& arr) {
        
        int n=arr.size();
        int ans=0;
        vector<int>srt;
        for(auto &x:arr)
        {
            srt.push_back(x);
        }
        sort(srt.begin(),srt.end());

        unordered_map<int,int>mp;
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            freq[srt[i]]++;
            bool k=fun(i,mp,freq);
            //cout<<i<<" "<<k<<endl;
            if(k)
            {
                ans++;
            }
        }
        return ans;
    }
};