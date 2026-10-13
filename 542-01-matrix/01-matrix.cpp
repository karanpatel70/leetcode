
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      queue<pair<pair<int,int>,int>> q;
      int m=mat.size();
      int n=mat[0].size();
      vector<vector<bool>> visited(m,vector<bool>(n,false));
      vector<vector<int>> ans(m,vector<int>(n,0));
      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                q.push({{i,j},0});
                visited[i][j]=true;
            }
        }
      }
      int row[]={-1,0,+1,0};
      int col[]={0,-1,0,+1};
      while(!q.empty())
      {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            auto front=q.front();
             int first=front.first.first;
             int second=front.first.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int dx=first+row[i];
                int dc=second+col[i];
                if(dx<m && dx>=0 && dc<n && dc>=0 && !visited[dx][dc])
                {
                    visited[dx][dc]=true;
                    ans[dx][dc]=front.second+1;
                    q.push({{dx,dc},front.second+1});
                }
            }
        }
      }
      return ans;
    }
};
