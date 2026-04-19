class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int best=0;
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        while(i<n && j<m)
        {

            if(j<i) j=i;
            while(j<m && nums1[i]<=nums2[j])
            {
                best=max(best,j-i);
                j++;
            }
            i++;

        }
        return best;
    }
};