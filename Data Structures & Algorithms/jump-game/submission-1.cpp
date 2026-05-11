class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;
        for(int i = n - 2; i > -1; i--){
            if(nums[i] >= goal - i) goal = i;
        }
        if(goal == 0) return true;
        else return false;
    }
};
