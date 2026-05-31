// 輪流當頭，小的先放進來
class Solution {
public:
    vector<vector<int>> result;
    void combine(vector<int>& nums, vector<int>& path, int target, int index){
        if(target == 0){
            result.push_back(path);
        }
        else if(target < 0){
            return;
        }
        else{
            for(int i = index; i < nums.size(); i++){
                path.push_back(nums[i]);
                combine(nums, path, target - nums[i], i);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sorted_nums = nums;
        vector<int> path;
        sort(sorted_nums.begin(), sorted_nums.end());
        combine(sorted_nums, path, target, 0);
        return result;
    }
};
