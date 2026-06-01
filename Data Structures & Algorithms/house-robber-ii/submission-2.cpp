class Solution {
private:
    int rob_max(vector<int>& nums, int start, int end){
        int first = 0;
        int second = 0;
        for(int i = start; i <= end; i++){
            int curr = max(first + nums[i], second);
            first = second;
            second = curr; 
        }
        return second;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(rob_max(nums, 0, nums.size() - 2), rob_max(nums, 1, nums.size() - 1));
    }
};
