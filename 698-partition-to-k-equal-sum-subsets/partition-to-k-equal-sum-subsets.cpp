
class Solution {
public:
    bool solve(vector<int>& nums, vector<bool>& visited,
               int k, int currSum, int target, int start) {

        if (k == 1)
            return true;

        if (currSum == target)
            return solve(nums, visited, k - 1, 0, target, 0);

        int prev = -1;

        for (int i = start; i < nums.size(); i++) {
            if (visited[i])
                continue;

            // Skip duplicate values at this recursion level
            if (nums[i] == prev)
                continue;

            if (currSum + nums[i] > target)
                continue;

            visited[i] = true;

            if (solve(nums, visited, k, currSum + nums[i],
                      target, i + 1))
                return true;

            visited[i] = false;
            prev = nums[i];

            // If the first choice in an empty subset fails,
            // other choices at this level are unnecessary.
            if (currSum == 0)
                return false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % k != 0)
            return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        vector<bool> visited(nums.size(), false);

        return solve(nums, visited, k, 0, target, 0);
    }
};
