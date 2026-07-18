class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Edge case
        if(s.length() == 0)
        {
            return 0;
        }
        int maxLength {1};
        int length {1};
        int left {0};
        unordered_map<char, int> seen;

        for(int right = 0; right < s.length(); right++)
        {
            //Slide window left
            while(seen.contains(s[right]))
            {
                seen.erase(s[left]);
                left += 1;
            }
            
            //Expand window
            seen[s[right]]++;
            length = right - left + 1; 
            if(length > maxLength)
            {
                maxLength = length;
            }
        }

        return maxLength;
    }
};
