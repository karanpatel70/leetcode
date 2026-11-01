class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        vector<int> ans;
        for(auto it:m)
        {
           if(it.second>=2)
           {
            ans.push_back(it.first);
            ans.push_back(it.first);
           }
           else if(it.second==1)
           {
            ans.push_back(it.first);
           }
        }
        nums=ans;
        return nums.size();
    }
};