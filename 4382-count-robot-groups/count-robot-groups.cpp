class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=speed.size();
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
              s.push(i);
              continue;
            }
            int r=s.top();
            if(position[i+1]-position[i]<=distance || speed[i]>speed[r])
            {
                continue;
            }
            else
            {
                s.push(i);
            }
        }
        return s.size();
    }
};