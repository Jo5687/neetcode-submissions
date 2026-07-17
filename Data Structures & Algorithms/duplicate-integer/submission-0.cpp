class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> seenNums{};
        for(int i = 0; i < nums.size(); i++)
        {
            if(auto hasNum = seenNums.find(nums[i]); hasNum != seenNums.end())
            {
                return true;
            }
            seenNums[nums[i]] = i;
        }
        return false;
    }
};