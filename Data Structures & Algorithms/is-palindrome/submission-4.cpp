class Solution {
private:
    bool check(vector<char>& nns, int left, int right){
        while(left < right){
            if(tolower(nns[left]) == tolower(nns[right])){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        vector<char> nns;
        for(char c : s){
            if(isalnum(c)){
                nns.push_back(c);
            }
        }
        int n = nns.size();
        if(n == 1) return true;

        return check(nns, 0, n - 1);
    }
};
