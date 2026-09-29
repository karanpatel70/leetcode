class Solution {
public:
    int find(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j,int m,int n)
    {
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(find(grid,dp,i+1,j,m,n),find(grid,dp,i,j+1,m,n));
    }
    int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
    return find(grid,dp,0,0,m,n);  
    }
};