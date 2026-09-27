class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        
        int n=nums.size();

        
        int b = 0;

        map<pair<int,int>, int> mp;
        for(int i = 1; i < n; i++) {
            
            if(nums[i] == nums[i-1]) {
                b++;
            }
            else {
                int x = min(nums[i], nums[i-1]);
                int y = max(nums[i], nums[i-1]);
                mp[{x, y}]++;
            }
        }
        int best = 0;
        for(auto &it : mp) {
            best = max(best, it.second);
        }
        return b + best;
    }
};