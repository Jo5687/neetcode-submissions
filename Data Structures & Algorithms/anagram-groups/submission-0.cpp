class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupMap;
        //Build map
        for(string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            groupMap[key].push_back(s);
        }
        //Return map groups
        vector<vector<string>> groups{};
        for(auto& group : groupMap)
        {
            groups.push_back(group.second);
        }
        return groups;
    }
};
