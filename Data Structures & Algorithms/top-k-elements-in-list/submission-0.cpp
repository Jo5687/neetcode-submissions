class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numMap{}; //Value, frequency
        //Build map
        for(int i : nums)
        {
            numMap[i]++;
        }
        //Sort map into vector
        vector<vector<int>> numValues{};
        for(const auto& [num, freq] : numMap)
        {
            numValues.push_back({freq, num});
        }
        sort(numValues.begin(), numValues.end());
        vector<int> returnVals{};
        while(k > 0)
        {
            returnVals.push_back(numValues.back()[1]);
            numValues.pop_back();
            k--;
        }
        return returnVals;
    }
};
