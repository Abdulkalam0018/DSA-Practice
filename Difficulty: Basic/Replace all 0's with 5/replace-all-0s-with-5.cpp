/*you are required to complete this method*/
class Solution {
  public:
    int convertFive(int n) {
        // Your code here
        int ans=0;
        string s=to_string(n);
        int p=s.size();
        for(int i=0;i<p;i++)
        {
            int k=s[i]-'0';
            if(k==0){
                ans=ans*10+5;
            }
            else{
                ans=ans*10+k;
            }
        }
        return ans;
    }
};