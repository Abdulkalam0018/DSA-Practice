class Solution {
  public:
    int closest3Sum(vector<int> &arr, int tar) {
        int n = (int)arr.size();
        sort(arr.begin(), arr.end());

        int best = arr[0] + arr[1] + arr[2];

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];

                if (abs(sum - tar) < abs(best - tar) || (abs(sum - tar) == abs(best - tar) && sum > best))
                    {
                        best = sum;
                    }

                if (sum == tar) {
                    return tar;
                } else if (sum < tar) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return best;
    }
};