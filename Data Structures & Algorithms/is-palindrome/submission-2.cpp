class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> sta;
        string cleaned = "";
        for(char c : s){
            if(isalnum(c)){
                char lower_c = tolower(c);
                sta.push(lower_c);
                cleaned += lower_c;
            }
        }
        for(char c : cleaned){
            if(sta.top() != c) return false;
            else{
                sta.pop();
            }
        }
        return sta.empty();
    }
};
