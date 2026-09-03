class Solution {
public: 
    int find(vector<int>& nums,int i,int free,int n,vector<vector<int>>& dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][free]!=-1)
        {
            return dp[i][free];
        }
        if(free==0)
        {
          return dp[i][free]=find(nums,i+1,1,n,dp); 
        }
         int a=nums[i]+find(nums,i+1,0,n,dp);
         int b=find(nums,i+1,1,n,dp);
        return dp[i][free]=max(a,b);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++)
        {
            vector<int> temp(2,-1);
            dp[i]=temp;
        }
        return find(nums,0,1,n,dp);
    }
};