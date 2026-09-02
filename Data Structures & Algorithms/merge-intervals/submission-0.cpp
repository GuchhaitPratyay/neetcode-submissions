class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);

        for (int i = 0; i < intervals.size(); ++i) {
            int startTime = intervals[i][0];
            int endTime = intervals[i][1];

            int lastEndTime = result.back()[1];

            if (startTime <= lastEndTime) {
                //keep on updating with the maximum end time
                result.back()[1] = max(endTime, lastEndTime);
            } else {
                //I found a new interval
                result.push_back({startTime, endTime});
            }
        }

        return result;
    }
};
