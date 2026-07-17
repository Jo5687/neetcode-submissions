class Solution {
public:
    bool isPalindrome(string s) {
        //Clean up string
        //Remove non-alphanumeric
        std::erase_if(s, [](unsigned char c) 
        {
            return !std::isalnum(c);
        });
        //Make lowercase
        transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c)
        { 
            return tolower(c); 
        });

        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            if(tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
};
