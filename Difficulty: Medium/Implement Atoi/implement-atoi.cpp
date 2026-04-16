class Solution {
  public:
    #define ll long long
    int myAtoi(string &s) {
        // code here
        bool sign=true;
        int i=0;
        while(s[i]==' ' || s[i]=='+') i++;
        if(s[i]=='-')
        {
            sign=false;
            i++;
        }
        while(s[i]=='0') i++;
        ll ans=0;
        while(!(s[i]=='\0' ||( s[i]<'0' || s[i]>'9')))
        {
            ans*=10;
            ans+=(s[i]-'0');
            i++;
        }
        int p=INT_MIN;
        if(sign && ans<INT_MAX) return ans;
        else if(sign && ans>=INT_MAX) return INT_MAX;
        else if(!sign && ans<=INT_MAX) return -1*ans;
        return p;
        
    }
};
