class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int cnt=0;
        int best=INT_MIN;
        int cnt1=0;
        for(auto &x:arr)
        {
            if(x==1)
            {
                cnt1++;
                cnt--;
                if(cnt<0) cnt=0;
                
            }
            else
            {
                cnt++;
                best=max(best,cnt);
            }
        } 
        if(best==INT_MIN) return cnt1;
        return cnt1+best;
        
    }
};