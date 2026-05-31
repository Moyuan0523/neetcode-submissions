// hash map 紀錄元素出現位置，若再次遇到，便直接跳到該位置 +1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxSubstrlen = 0;
        unordered_map<char, int> last_seen;

        for(int right = 0; right < s.size(); right++){
            if(last_seen.find(s[right]) != last_seen.end()){
                left = max(left, last_seen[s[right]] + 1);
            }
            last_seen[s[right]] = right;
            
            maxSubstrlen = max(maxSubstrlen, right - left + 1);
        }

        return maxSubstrlen; 
    }
};
