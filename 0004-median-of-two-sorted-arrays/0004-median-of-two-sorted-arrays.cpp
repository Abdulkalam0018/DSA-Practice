class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1;

        int totalLeft = (n1 + n2 + 1) / 2;

        while (low <= high) {

            int i1 = (low + high) / 2;
            int i2 = totalLeft - i1;

            int max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
            int min1 = (i1 == n1) ? INT_MAX : nums1[i1];

            int max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];
            int min2 = (i2 == n2) ? INT_MAX : nums2[i2];

            // Correct partition found
            if (max1 <= min2 && max2 <= min1) {

                // Odd total elements
                if ((n1 + n2) % 2)
                    return max(max1, max2);

                // Even total elements
                return (max(max1, max2) + min(min1, min2)) / 2.0;
            }

            // Too many elements taken from nums1
            else if (max1 > min2) {
                high = i1 - 1;
            }

            // Too few elements taken from nums1
            else {
                low = i1 + 1;
            }
        }

        return 0.0;
    }
};