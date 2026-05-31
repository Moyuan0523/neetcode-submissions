// 輪流當頭，小的先放進來
// edge case : 1 or 10
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void combine(vector<int>& nums, int target, int index){
        if(target == 0){
            result.push_back(path);
            return;
        }
        else if(target < 0){
            return;
        }
        else{
            for(int i = index; i < nums.size(); i++){
                path.push_back(nums[i]);
                combine(nums, target - nums[i], i);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        combine(sorted_nums, target, 0);
        return result;
    }
};
