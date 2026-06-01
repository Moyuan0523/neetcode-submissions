class Solution {
public:
    int rob(vector<int>& nums) {
        int first = 0;
        int sec = 0;
        for(int i = 0; i < nums.size(); i++){
            int curr = max(first + nums[i], sec);
            first = sec;
            sec = curr;
        }
        return sec;
    }
};
