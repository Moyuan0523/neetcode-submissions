// 重複換人當頭
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void findSubset(vector<int>& nums, int index){
        result.push_back(path);
        for(int i = index; i < nums.size(); i++){
            path.push_back(nums[i]);
            findSubset(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sorted_num = nums;
        findSubset(nums, 0);
        return result;
    }
};
