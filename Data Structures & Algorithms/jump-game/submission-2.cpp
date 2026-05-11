// Greedy 從最後開始，判斷 n-2 是否可以到 goal = n-1，可以的話 goal 往前到該位置（之後只需要到 n-2 即可），繼續 iterative
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
