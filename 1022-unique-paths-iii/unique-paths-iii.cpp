class Solution {
public:
int m;
int n;
int cnt=0;
int starti;
int startj;
int totals=0;
void find(vector<vector<int>>& grid,int m,int n,int cnt,int i,int j)
{
    if(i>=m || i<0 || j>=n || j<0)
    {
        return ;
    }
    if(grid[i][j]==2)
    {
        if(cnt==0)
        {
            totals+=1;
        }
        return;
    }
    if(grid[i][j]==-1)
    {
        return;
    }
    grid[i][j]=-1;
    find(grid,m,n,cnt-1,i+1,j);
    find(grid,m,n,cnt-1,i-1,j);
    find(grid,m,n,cnt-1,i,j-1);
    find(grid,m,n,cnt-1,i,j+1);
    grid[i][j]=0;   
}
    int uniquePathsIII(vector<vector<int>>& grid) {
    vector<vector<int>> start;
    vector<vector<int>> end;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]==1)
            {
                starti=i;
                startj=j;
            }
            else if(grid[i][j]==0)
            {
              cnt++;
            }
        }
    } 
    cnt+=1;
    m=grid.size();
    n=grid[0].size(); 
    find(grid,m,n,cnt,starti,startj);
    return totals;
    }
};