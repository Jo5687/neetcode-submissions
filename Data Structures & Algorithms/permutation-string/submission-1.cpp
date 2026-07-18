class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> substringMap{}; //Character, frequency
        for(char c: s1)
        {
            substringMap[c]++;
        }

        //Build window
        int left = 0;
        int right = s1.length() - 1;
        unordered_map<char, int> stringMap{};
        for(int i = 0; i <= right; i++)
        {
            stringMap[s2[i]]++;
        }

        //Move window
        while(right < s2.length())
        {
            //Compare
            if(substringMap == stringMap)
            {
                return true;
            }
            //Shift window right
            stringMap[s2[left]]--;
            if(stringMap[s2[left]] == 0)
            {
                stringMap.erase(s2[left]);
            }
            left++;

            right++;
            stringMap[s2[right]]++;
        }
        return false;
    }
};
