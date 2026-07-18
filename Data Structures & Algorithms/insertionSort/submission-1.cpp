// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        if(pairs.size() == 0)
        {
            return {};
        }
        vector<vector<Pair>> states{};
        //Put initial state
        states.push_back(pairs);

        for(int i = 1; i < pairs.size(); i++)
        {
            int currKey = pairs[i].key;
            string currValue = pairs[i].value;
            int j = i - 1;
            //Move through sorted section
            while(j >= 0 && currKey < pairs[j].key)
            {
                //Move right
                pairs[j + 1] = pairs[j];
                j--;
            }
            //Insert element
            pairs[j + 1] = {currKey, currValue};
            //Append current state
            states.push_back(pairs);
        }
        return states;
    }
};
