class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        vector<int>buy(k+1,INT_MIN);
        vector<int>profit(k+1,INT_MIN);
        int n=prices.size();
        profit[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                buy[j]=max(buy[j],profit[j-1]-prices[i]);
                profit[j]=max(profit[j],prices[i]+buy[j]);
            }
            //cout<<profit[k]<<endl;
        }
        return profit[k];

    }
};