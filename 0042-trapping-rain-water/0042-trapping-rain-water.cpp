class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        vector<int>pref(n,0),suf(n,0);

        int a=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(height[i]>a)
            {
                a=height[i];
                suf[i]=a;
            }
            else
            {
                suf[i]=a;
            }
        }
        a=height[0];
        for(int i=1;i<n;i++)
        {
            if(height[i]>a)
            {
                a=height[i];
                pref[i]=a;
            }
            else
            {
                pref[i]=a;
            }
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            int b=min(pref[i],suf[i]);
            if(b>height[i])
            {
                ans+=b-height[i];
            }
        }
        return ans;

    }
};