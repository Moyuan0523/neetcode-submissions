// bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 統計數字出現頻率
        unordered_map<int, int> freqs;
        for(int num : nums){
            freqs[num]++;
        }
        // 加入 bucket
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto& [num, freq] : freqs){
            buckets[freq].push_back(num);
        }
        // 從最大的開始倒出
        vector<int> result;
        for(int i = nums.size(); i >= 0; i--){
            for(int num : buckets[i]){
                result.push_back(num);
                if(result.size() == k) return result;
            }
        }
    }
};
