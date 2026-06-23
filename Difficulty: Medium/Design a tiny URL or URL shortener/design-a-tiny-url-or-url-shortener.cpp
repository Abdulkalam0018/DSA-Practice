class Solution {
  public:

    // Function to generate a short url from integer ID
    string idToShortURL(long long int n) {
        // code here
        map<int,char>mp;
        char ch='a';
        for(int i=0;i<26;i++)
        {
            mp[i]=ch;
            ch++;
        }
        ch='A';
        for(int i=26;i<52;i++)
        {
            mp[i]=ch;
            ch++;
        }
        ch='0';
        for(int i=52;i<62;i++)
        {
            mp[i]=ch;
            ch++;
        }
        string s="";
        while(n>=62)
        {
            int a=n%62;
            s=mp[a]+s;
            n=(1LL*n/62);
        }
        int a=n%62;
        s=mp[a]+s;
        return s;
        
    }
};