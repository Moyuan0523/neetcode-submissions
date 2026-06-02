/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 1) return true;

        vector<Interval> new_intervals = intervals;
        sort(new_intervals.begin(), new_intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int prev = -1;
        for(Interval i : new_intervals){
            if(i.start < prev){
                return false;
            }
            prev = i.end;
        }

        return true;
    }
};
