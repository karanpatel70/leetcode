class Solution {
public:
    void doitrow(vector<vector<int>>& ans,vector<vector<int>>& grid,int rs,vector<int>& rowShift,int n)
    {
        int shift=rowShift[rs];
        for(int i=0;i<grid.size();i++)
        {
            ans[rs][i]=grid[rs][(i+shift)%n];
        }
    }
   void doitcol(vector<vector<int>>& ans2,vector<vector<int>>& ans,int cs,vector<int>& colShift,int m)
    {
        int shift=colShift[cs];
        for(int i=0;i<ans.size();i++)
        {
            ans2[i][cs]=ans[(i+shift)%m][cs];
        }
    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> ans=grid;
        int m=grid[0].size();
        for(int i=0;i<rowShift.size();i++)
        {
            doitrow(ans,grid,i,rowShift,n);
        }
        vector<vector<int>> ans2=ans;
        for(int i=0;i<colShift.size();i++)
        {
            doitcol(ans2,ans,i,colShift,m);
        }
       return ans2; 
    }
};