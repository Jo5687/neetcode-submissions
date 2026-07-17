class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets{};
        int length = nums.size();
        //Sort array
        sort(nums.begin(), nums.end());
        //Go through anchor values
        for(int anchor = 0; anchor < length - 2; anchor++)
        {
            //Skip duplicate anchors
            if(anchor > 0 && nums[anchor] == nums[anchor - 1])
            {
                continue;
            }
            //Get target value
            int target = 0 - nums[anchor];
            //Two-pointer
            int left = anchor + 1;
            int right = length - 1;
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                if(sum < target)
                {
                    left++;
                }
                else if(sum > target)
                {
                    right--;
                }
                else
                {
                    triplets.push_back({nums[anchor], nums[left], nums[right]});
                    left++;
                    right--;
                    //Skip duplicates
                    while(left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while(right > left && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }
        }
        return triplets;
    }
};
