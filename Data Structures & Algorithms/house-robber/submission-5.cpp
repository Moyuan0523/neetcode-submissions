// 偷與不偷兩個選項
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int first = nums[0];
        int sec = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++){
            int curr = max(first + nums[i], sec);
            first = sec;
            sec = curr;
        }

        return sec;
    }
};
