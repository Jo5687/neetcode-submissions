class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxLength {1};
        int currentLength {1};
        for(int i = 1; i < nums.size(); i++)
        {
            //Skip duplicates
            if(nums[i] == nums[i - 1])
            {
                continue;
            }
            if(nums[i] - nums[i - 1] == 1)
            {
                currentLength++;
                if(currentLength > maxLength)
                {
                    maxLength = currentLength;
                }
            }
            else
            {
                currentLength = 1;
            }
        }
        return maxLength;
    }
};
