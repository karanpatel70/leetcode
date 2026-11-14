class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        vector<string> ans;
        for(int i=1;i<nums.size();i+=2)
        {
            string s=to_string(nums[i]);
            string y=to_string(nums[i-1]);
            string res=y+s;
            ans.push_back(res);
        }
        vector<int> real;
        for(int i=0;i<ans.size();i++)
        {
            int n=stoi(ans[i]);
            real.push_back(n);
        }
        sort(real.begin(),real.end());
        return real[0];
    }
};