class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int counter[26] = {0};
        for(int i = 0; i < s.length(); i++){
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }
        for(int c : counter){
            if(c != 0) return false;
        }
        return true;
    }
};
