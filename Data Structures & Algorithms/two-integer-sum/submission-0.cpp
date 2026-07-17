class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen {}; //Value, index
        for(int i = 0; i < nums.size(); i++)
        {
            int desired = target - nums[i];
            if(auto has = seen.find(desired); has != seen.end())
            {
                return {seen[desired], i};
            }
            seen[nums[i]] = i;
        }
    }
};
