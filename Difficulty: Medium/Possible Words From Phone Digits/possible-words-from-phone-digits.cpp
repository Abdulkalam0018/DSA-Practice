class Solution {
  public:
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string>ans;
        
        map<int,vector<char>>mp;
        
        char ch='a';
        for(int i=2;i<=9;i++)
        {
          if(i<7 || i==8)
          {
              int k=3;
              while(k)
              {
                  mp[i].push_back(ch);
                  ch++;
                  k--;
              }
          }
          else
          {
              int k=4;
              while(k)
              {
                  mp[i].push_back(ch);
                  ch++;
                  k--;
              }
          }
        }
        
        // for(auto &x:mp[arr[0]])
        // {
        //     string s="";
        //     s+=x;
        //     ans.push_back(s);
        // }
        // for(auto &x:ans)
        // {
        //     cout<<x<<" ";
        // }
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            vector<string>ans1;
            if(arr[i]>1 && arr[i]<=9)
            {
                if(ans.size()==0)
                {
                    for(auto &x:mp[arr[i]])
                    {
                            string str="";
                            str+=x;
                            ans.push_back(str);
                    }
                    continue;
                }
                for(auto &x:mp[arr[i]])
                {

                    
                    for(auto &y:ans)
                    {
                       string str=y;
                       str+=x;
                       ans1.push_back(str);
                    }
                }
                ans=ans1;
            }
            
        }
        return ans;
    }
};