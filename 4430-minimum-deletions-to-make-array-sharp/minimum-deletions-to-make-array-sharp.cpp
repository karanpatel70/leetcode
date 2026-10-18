class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt=0;
        //sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i]^nums[i-1])==0)
            {
               cnt++;
            } 
        }
        return cnt;
    }
};