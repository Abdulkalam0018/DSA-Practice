class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        vector<int>buy(k+1,INT_MAX);
        vector<int>profit(k+1,0);
        profit[0]=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                buy[j]=min(prices[i]-profit[j-1],buy[j]);
                profit[j]=max(profit[j],prices[i]-buy[j]);
            }
        }
        return profit[k];

    }
};