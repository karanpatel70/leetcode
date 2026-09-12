class Solution {
public:
    void dfs(int idx,vector<vector<int>>& isconnected,vector<bool>& visited)
    {
        visited[idx]=true;
        for(int next=0;next<isconnected.size();next++)
        {
            if(!visited[next] && isconnected[idx][next]==1)
            {
                dfs(next,isconnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n=isconnected.size();
        vector<bool> visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(i,isconnected,visited);
            }
        }
        return cnt;
    }
};