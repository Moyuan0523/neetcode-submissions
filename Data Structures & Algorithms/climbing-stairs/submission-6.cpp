// dp ，只依賴他的前兩個解
class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int sec = 1;

        for(int i = 0; i < n - 1; i++){
            int temp = sec;
            sec = first + sec;
            first = temp;
        }

        return sec;
    }
};
