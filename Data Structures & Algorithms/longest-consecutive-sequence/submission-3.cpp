// scan 所有，若 num-1 未出現，便表示他是 sequence 的頭，往後計算
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int n = nums.size();
        int longest = 0;
        for(int num : nums){
            if(seen.count(num - 1)){
                continue;
            }
            else{
                int curr_n = num;
                int curr_len = 1;
                while(seen.count(curr_n + 1)){
                    curr_len++;
                    curr_n++;
                }
                longest = max(longest, curr_len);
            }
        }
        return longest;
    }
};
