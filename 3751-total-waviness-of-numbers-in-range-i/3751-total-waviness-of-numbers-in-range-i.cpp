class Solution {
public:
    int countwaviness(int n)
    {
        string s=to_string(n);
        int k=s.size();
        if(k<3) return 0;

        int cnt=0;
        for(int i=1;i<k-1;i++)
        {
            if(s[i-1]<s[i] && s[i+1]<s[i]) cnt++;
            if(s[i-1]>s[i] && s[i+1]>s[i]) cnt++;

        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++)
        {
            ans+=countwaviness(i);
        } 
        return ans;
    }
};