class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> new_intervals = intervals;
        sort(new_intervals.begin(), new_intervals.end());
        int prevEnd = new_intervals[0][1];
        int res = 0;
        
        for(int i = 1; i < new_intervals.size(); i++){
            int start = new_intervals[i][0];
            int end = new_intervals[i][1];
            if(start >= prevEnd){
                prevEnd = end;
            }
            else{
                res += 1;
                prevEnd = min(prevEnd, end);
            }
        }

        return res;
    }
};
