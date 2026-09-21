class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
      
       vector<int> start;
       vector<int> end;
        for(int i=0;i<intervals.size();i++)
        {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        long long nonintersect=0;
        long long total=0;
        int n=intervals.size();
        total=1LL * n* (n-1) /2; 
        int p=0;
        for(int i=0;i<n;i++)
        {
            while(p<n && end[p]<start[i])
            {
                p++;
            }
            nonintersect+=p;
        }
        return total-nonintersect;
    }
};