class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> smap;
        for(string s : strs){
            int counter[26] = {0};
            for(char c : s){
                counter[c - 'a']++;
            }
            string key;
            for(int i = 0; i < 26; i++){
                key += to_string(counter[i]) + '#'; 
            }
            smap[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& pair : smap){
            result.push_back(pair.second);
        }
        return result;
    }
};
