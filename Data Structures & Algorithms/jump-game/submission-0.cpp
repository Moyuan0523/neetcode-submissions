class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;
        for(int i = n - 2; i > -1; i--){
            int distance = goal - i;
            if(nums[i] >= distance) goal = i;
        }
        if(goal == 0) return true;
        else return false;
    }
};
