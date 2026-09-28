class Solution {
public:
    int find(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>& dp)
    {
         if(i>=m || j>=n)
        {
            return 0;
        }
        if(grid[i][j]==1)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=find(grid,i+1,j,m,n,dp)+find(grid,i,j+1,m,n,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return find(grid,0,0,m,n,dp);
    }
};