class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> smap;
        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            smap[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& pair : smap){
            result.push_back(pair.second);
        }
        return result;
    }
};
