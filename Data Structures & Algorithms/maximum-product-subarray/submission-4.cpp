class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else{
            int res = nums[0];
            int curMax = nums[0];
            int curMin = nums[0];

            for(int i = 1; i < nums.size(); i++){
                int temp = curMax * nums[i];
                curMax = max({nums[i], temp, curMin * nums[i]});
                curMin = min({nums[i], temp, curMin * nums[i]});
                res = max(res, curMax);
            }

            return res;
        }
    }
};
