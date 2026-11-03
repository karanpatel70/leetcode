class Solution {
public:
    int cnt = 0;

    void solve(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size()) {
            if (sum == target) cnt++;
            return;
        }
        solve(nums, i + 1, sum + nums[i], target);  // choose +
        solve(nums, i + 1, sum - nums[i], target);  // choose -
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums, 0, 0, target);
        return cnt;
    }
};