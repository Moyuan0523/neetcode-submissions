// dp
class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int sec = 1;
        for(int i = 0; i < n; i++){
            int curr = sec + first;
            first = sec;
            sec = curr;
        }
        return first;
    }
};
