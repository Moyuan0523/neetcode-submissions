class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left_parent;
        stack<int> star;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') left_parent.push(i);
            else if(s[i] == '*') star.push(i);
            else{
                if(left_parent.empty() && star.empty()){
                    return false;
                }
                else if(!left_parent.empty()){
                    left_parent.pop();
                }
                else{
                    star.pop();
                }
            }
        }
        while(!left_parent.empty() && !star.empty()){
            if(left_parent.top() > star.top()){
                return false;
            }
            else{
                left_parent.pop();
                star.pop();
            }
        }
        return left_parent.empty();
    }
};
