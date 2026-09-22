class Solution {
public:
    long long maxValue(vector<int>& nums) {
        long long base_pulse = 0;
        long long prefix = 0;
        
        // Track the maximum prefix sums we've seen so far.
        // We subtract the MAXIMUM previous prefix to get the MINIMUM subarray sum.
        long long max_even_pref = 0;
        long long max_odd_pref = -1e18; // Very small number to represent "empty"
        long long min_even_sum = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            // Apply the alternating sign for the pulse
            long long val = (i % 2 == 0) ? nums[i] : -nums[i];
            
            base_pulse += val;
            prefix += val;
            
            // Length of the prefix is i + 1
            if ((i + 1) % 2 == 0) {
                // Current prefix length is Even. Subtract max Even prefix seen so far.
                min_even_sum = min(min_even_sum, prefix - max_even_pref);
                max_even_pref = max(max_even_pref, prefix);
            } else {
                // Current prefix length is Odd. Subtract max Odd prefix seen so far.
                min_even_sum = min(min_even_sum, prefix - max_odd_pref);
                max_odd_pref = max(max_odd_pref, prefix);
            }
        }
        
        // The maximum new pulse is the original pulse minus twice the min even sum
        return base_pulse - 2 * min_even_sum;
    }
};