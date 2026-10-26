class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
      long long total = 0;
        vector<long long> gains;
        gains.reserve(nums.size());

        for (int x : nums) {
            total += x;

            string s = to_string(x);
            sort(s.begin(), s.end(), greater<char>());   // digits descending
            long long best = stoll(s);

            gains.push_back(best - x);
        }

        sort(gains.begin(), gains.end(), greater<long long>());

        for (int i = 0; i < k && i < (int)gains.size(); i++) {
            total += gains[i];
        }
        return total;
    }
};