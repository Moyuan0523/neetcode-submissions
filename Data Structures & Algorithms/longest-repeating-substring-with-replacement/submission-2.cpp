// 主角是目前出現最多的元素（n），只要 window_size - n <= k 就合法
// 用 unordered_map 紀錄元素出現的次數
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int left = 0;
        int maxCount = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++){
            counts[s[right]]++;
            maxCount = max(maxCount, counts[s[right]]);
            while((right - left + 1) - maxCount > k){
                counts[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
