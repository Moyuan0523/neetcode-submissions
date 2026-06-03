class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int left = 0;
        int right = 0;

        int curr_farest = 0;
        while(right < nums.size() - 1){
            for(int i = left; i <= right; i++){
                curr_farest = max(curr_farest, i + nums[i]);
            }
            left = right + 1;
            right = curr_farest;
            result++;
        }

        return result;
    }
};
