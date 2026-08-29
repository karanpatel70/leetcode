#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 1. Sort intervals primarily by end time
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int cnt = 0;
        int prev_end = intervals[0][1];

        // 2. Linear scan to check overlaps
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prev_end) {
                // Overlap detected -> greedily remove the one with larger end time
                cnt++;
            } else {
                // No overlap -> update prev_end to current interval's end time
                prev_end = intervals[i][1];
            }
        }

        return cnt;
    }
};