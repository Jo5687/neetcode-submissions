class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> products(length, 1);
        
        //Prefix products
        int prefix = 1;
        for (int i = 0; i < length; i++)
        {
            products[i] *= prefix;
            prefix *= nums[i];
        }

        //Suffix products
        int suffix = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            products[i] *= suffix;
            suffix *= nums[i];
        }

        return products;
    }
};
