class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) {
            for (int i = 1; i < n; i++) {
                if (nums[i] == 0 && nums[i - 1] == 0)
                    return true;
            }
            return false;
        }

        unordered_map<int, int> mp;
        mp[0] = -1;  

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int rem = sum % k;

            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;
            }
        }

        return false;
    }
};