class Solution {
public:

    string encode(vector<string>& strs) {
        string temp;
        for(string& s : strs){
            int len = s.size();
            temp += to_string(len) + '#' + s;
        }
        return temp;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> result;
        int i = 0;
        while(i < n){
            int j = i;
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));
            int start = j + 1;
            result.push_back(s.substr(start, len));
            i = start + len;
        }
        return result;
    }
};
