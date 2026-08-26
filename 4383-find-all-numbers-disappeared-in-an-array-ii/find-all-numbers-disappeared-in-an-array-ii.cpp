class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int prev=lower-1;
       for(int x:nums)
           {     
               if(x<lower || x>upper) continue;

               if(prev+1<=x-1)
               {
                   ans.push_back({prev+1,x-1});
               }
               prev=x;  
            }
        if(prev+1<=upper)
               {
                   ans.push_back({prev+1,upper});
               }   
        return ans;
    }
};