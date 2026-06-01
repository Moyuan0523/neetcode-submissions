// 前至後比對有沒有重疊
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};

        vector<vector<int>> result;
        vector<vector<int>> sorted_intervals = intervals;
        sort(sorted_intervals.begin(), sorted_intervals.end());
        result.push_back(sorted_intervals[0]);

        for(int i = 1; i < sorted_intervals.size(); i++){
            if(sorted_intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(result.back()[1], sorted_intervals[i][1]);
            }
            else{
                result.push_back(sorted_intervals[i]);
            }
        }
        return result;
    }
};
