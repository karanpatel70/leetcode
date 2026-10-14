class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O')
                {
                    q.push({i,j});
                    visited[i][j]=true;
                }
                else if(board[i][j]=='O')
                {
                    visited[i][j]=false;
                }
                else
                {
                    visited[i][j]=true;
                }
            }
        }
        int row[]={-1,0,+1,0};
        int col[]={0,+1,0,-1};
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                auto front=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int dx=front.first+row[i];
                    int dc=front.second+col[i];
                    if(dx<n && dx>=0 && dc<m && dc>=0 && visited[dx][dc]==false && board[dx][dc]=='O')
                    {
                        visited[dx][dc]=true;
                        q.push({dx,dc});
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==false && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};