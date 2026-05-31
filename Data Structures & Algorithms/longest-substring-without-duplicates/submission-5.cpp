class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int maxSubstr = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            if(seen.find(s[right]) != seen.end()){
                left = max(left, seen[s[right]] + 1);
            }
            seen[s[right]] = right;
            maxSubstr = max(maxSubstr, right - left + 1);
        } 
        return maxSubstr;
    }
};
