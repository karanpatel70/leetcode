class Solution {
public:
    vector<int> findfactor(int x)
    {
        vector<int> ans;
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
            {
                ans.push_back(i);
                while(x%i==0)
                {
                    x=x/i;
                }
            }
        }
        if(x>1)
        {
            ans.push_back(x);
        }
        return ans;
    }
    int longestSubarray(vector<int>& nums, int k) {
        vector<vector<int>> factors(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            factors[i]=(findfactor(nums[i]));
        }
        int l=0;
        unordered_map<int,int> m;
        int val=0;
        for(int r=0;r<nums.size();r++)
        {
            for(int i:factors[r])
            {
                m[i]++;
            }
            if(m.size()>k)
            {
                for(int i:factors[l])
                {
                    m[i]--;
                    if(m[i]==0)
                    {
                        m.erase(i);
                    }
                }
                l++;
            }
            val=max(val,r-l+1);
        }
        return val;
    }
};