vector<long long> v1;
vector<long long> v2; 
bool proc = false;

class Solution {
public:
    void precompute() {
        if (proc) return;
        proc = true;
        
        v1.push_back(0);
        for (int len = 1; len <= 10; ++len) {
            int half_len = (len + 1) / 2;
            long long start = 1;
            for(int i = 1; i < half_len; ++i) start *= 10;
            long long end = start * 10 - 1;
            
            for (long long i = start; i <= end; ++i) {
                long long pal = i;
                long long temp = i;
                
                if (len % 2 != 0) temp /= 10;
            
                while (temp > 0) {
                    pal = pal * 10 + temp % 10;
                    temp /= 10;
                }
                
                if (pal % 2 == 0) v1.push_back(pal);
                else v2.push_back(pal);
            }
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
    }

    long long minOperations(vector<int>& nums) {
        precompute(); // This will now instantly skip on test case 2, 3, 4, etc.
        long long ans = 0;
        
        for (int a : nums) {
            long long b = LLONG_MAX; 
            
            if (a % 2 != 0) {
                auto it = lower_bound(v2.begin(), v2.end(), a);
                if (it != v2.end()) {
                    b = min(b, (*it - a) / 2);
                }
                if (it != v2.begin()) {
                    auto it_prev = it - 1;
                    b = min(b, (a - *it_prev) / 2);
                }
            } else {
                auto it = lower_bound(v1.begin(), v1.end(), a);
                if (it != v1.end()) {
                    b = min(b, (*it - a) / 2);
                }
                if (it != v1.begin()) {
                    auto it_prev = it - 1;
                    b = min(b, (a - *it_prev) / 2);
                }
            }
            ans += b;
        }
        return ans;
    }
};