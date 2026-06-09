class Solution {
public:
    int maxScore(vector<int>& cp, int k) {

        int n=cp.size();
        int ans=0;
        int total=accumulate(cp.begin(),cp.end(),0);

        k=n-k;

        int tar=0;
        int a=k;
        for(int i=0;i<k;i++)
        {
            tar+=cp[i];
        }
        ans=total-tar;
        int j=a;
        int i=0;
        while(j<n)
        {
            tar-=cp[i];
            tar+=cp[j];
            i++;
            j++;
            ans=max(ans,total-tar);
        }
        return ans;

    }
};