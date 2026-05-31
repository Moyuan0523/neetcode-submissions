class Solution {
public:

    string encode(vector<string>& strs) {
        string temp;
        for(string s : strs){
            int n = s.size();
            temp += to_string(n) + '#' + s;
        }
        return temp;
    }

    vector<string> decode(string s) {
        int i = 0;
        int n = s.size();
        vector<string> result;
        while(i < n){
            int j = i;
            while(s[j] != '#') j++;
            int length = stoi(s.substr(i, j - i));
            int start = j + 1;
            result.push_back(s.substr(start, length));

            i = start + length;
        }
        return result;
    }
};
