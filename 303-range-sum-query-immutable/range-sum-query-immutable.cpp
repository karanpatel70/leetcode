class NumArray {
public:
    vector<int> pref;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        pref.assign(n + 1, 0);          // pref[0] = 0
        for (int i = 1; i <= n; i++) {  // i goes up to n
            pref[i] = pref[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left, int right) {
        return pref[right + 1] - pref[left];
    }
};