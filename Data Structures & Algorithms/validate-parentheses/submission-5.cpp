class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parent = {{')','('},{']','['},{'}','{'}};
        stack<char> st;
        for(char c : s){
            if(parent.find(c) != parent.end()){
                if(st.empty() || st.top() != parent[c]){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(c);
            }
        }
        return st.empty();
    }
};
