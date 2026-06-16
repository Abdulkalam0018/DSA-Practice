class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum=0;
        int sqsum=0;

        int a=n;
        while(n)
        {
            sum+=n%10;
            n=n/10;

        }
        while(a)
        {
            int b=a%10;
            sqsum=sqsum+(1LL*b*b);
            a=a/10;
        }
        return (sqsum-sum)>=50;
    }
};