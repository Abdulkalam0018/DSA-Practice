class Solution {
public:
    static const int mod = 1000000007;

    long long power(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long x) {
        return power(x, mod - 2);
    }

    int computeValue(int n) {
        int total = 2 * n;

        vector<long long> fact(total + 1, 1);

        for (int i = 1; i <= total; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        long long ans = fact[total];
        ans = (ans * modInverse(fact[n])) % mod;
        ans = (ans * modInverse(fact[n])) % mod;

        return ans;
    }
};