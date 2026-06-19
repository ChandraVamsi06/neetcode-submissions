class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> s;
        for(string i: strs) {
            string temp = i;
            sort(temp.begin(), temp.end());
            s[temp].push_back(i);
        }
        vector<vector<string>> res;
        for(auto i: s) {
            res.push_back(i.second);
        }
        return res;
    }
};
