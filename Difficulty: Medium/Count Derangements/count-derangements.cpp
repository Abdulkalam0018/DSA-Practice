class Solution {
  public:
    int derangeCount(int n) {
        // solve this question using the dp like tranform it into subproblem
        // take example of 5 friend
        // if you take element of another friend and here comes two cases
        // if they take means swap with you you both can leave 
        // there will be three people left
        // but if they not choose your element then 4 people left in
        // the room
        
        int a=0;
        int b=1;
        int ans=0;
        if(n==2) return b;
        for(int i=3;i<=n;i++)
        {
            ans=(1LL*(i-1)*(a+b));
            a=b;
            b=ans;
            
        }
        return ans;
        
    }
};