// dp
class Solution {
public:
    int climbStairs(int n) {
        int first = 0;
        int sec = 1;
        for(int i = 0; i < n; i++){
            int curr = first + sec;
            first = sec;
            sec = curr;
        }
        return sec;
    }
};
