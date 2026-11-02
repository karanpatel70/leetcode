
class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        int totalSum = accumulate(
            nums.begin(), nums.end(), 0
        );

        vector<vector<int>> left(n + 1);
        vector<vector<int>> right(n + 1);

        // Generate all subset sums
        for (int mask = 0; mask < (1 << n); mask++) {

            int sum1 = 0;
            int sum2 = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    sum1 += nums[i];
                    sum2 += nums[i + n];

                    cnt++;
                }
            }

            left[cnt].push_back(sum1);
            right[cnt].push_back(sum2);
        }

        // Sort right-side subset sums
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // Choose exactly n elements
        for (int k = 0; k <= n; k++) {

            for (int x : left[k]) {

                int need = totalSum / 2 - x;

                // Need n-k elements from right
                auto &arr = right[n - k];

                auto it = lower_bound(
                    arr.begin(), arr.end(), need
                );

                // Check current element
                if (it != arr.end()) {

                    int sum = x + *it;

                    ans = min(
                        ans,
                        abs(totalSum - 2 * sum)
                    );
                }

                // Check previous element
                if (it != arr.begin()) {

                    --it;

                    int sum = x + *it;

                    ans = min(
                        ans,
                        abs(totalSum - 2 * sum)
                    );
                }
            }
        }

        return ans;
    }
};
