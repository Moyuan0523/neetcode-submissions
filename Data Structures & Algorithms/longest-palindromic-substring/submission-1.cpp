// 中心擴散法
class Solution {
private:
    int extendLen(string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int start = 0;
        int maxLen = 1;
        for(int i = 0; i < s.size(); i++){
            int oddLen = extendLen(s, i, i);
            int evenLen = extendLen(s, i, i + 1);

            int len = max(oddLen, evenLen);

            if(maxLen < len){
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};
