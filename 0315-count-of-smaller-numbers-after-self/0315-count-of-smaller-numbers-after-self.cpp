class Solution {
public:
    using ii=pair<int,int>;
    void merge(vector<ii>&nums,int i,int mid,int j,vector<int>&count)
    {
        vector<ii>a,b;

        for(int k=i;k<=mid;k++)
        {
            a.push_back({nums[k].first,nums[k].second});
        }
        for(int k=mid+1;k<=j;k++)
        {
            b.push_back({nums[k].first,nums[k].second});
        }
        int right=0;

        int c=0;
        int d=0;
        int n=mid-i+1;
        int m=j-mid;

        int total=i;
        while(c<n && d<m)
        {
            if(b[d].first<a[c].first)
            {
                right++;
                nums[total]=b[d];
                d++;
            }
            else
            {
                count[a[c].second]+=right;
                nums[total]=a[c];
                c++;
            }
            total++;
        }
        while(c<n)
        {
            nums[total]=a[c];
            total++;
            count[a[c].second]+=right;
            c++;
        }
        while(d<m)
        {
            nums[total]=b[d];
       
            total++;
            d++;
        }
    }
    void mergesort(vector<ii>& nums,int i,int j,vector<int>&count)
    {
        if(i<j)
        {
            int mid=(i+j)/2;

            mergesort(nums,i,mid,count);
            mergesort(nums,mid+1,j,count);

            merge(nums,i,mid,j,count);


        }
    }
    vector<int> countSmaller(vector<int>& nums) {

        int n=nums.size();
        vector<int>count(n,0);

        
        vector<ii>nums1;

        for(int i=0;i<n;i++)
        {
            nums1.push_back({nums[i],i});
        }
        mergesort(nums1,0,n-1,count);
        return count;
    }
};