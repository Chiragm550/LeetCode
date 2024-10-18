class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
          [](const vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> res;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int idx = 1;

        while(idx < n){
            if(intervals[idx][0] <= end && intervals[idx][1] >= end || intervals[idx][0] >= start && intervals[idx][1] <= end){
                end = max(end, intervals[idx][1]);
            }
            else{
                res.push_back({start, end});
                start = intervals[idx][0];
                end = intervals[idx][1];
            }
            idx++;
        }

        res.push_back({start, end});

        return res;
    }
};