class Solution {
public:
    bool isValid(string s) {
        std::stack<char> brackets{};
        for(char c : s)
        {
            //Found open bracket, put on stack
            if(c == '(' || c == '{' || c == '[')
            {
                brackets.push(c);
            }
            //Found closed bracket, compare to top of stack
            if(c == ')' || c == '}' || c == ']')
            {
                //Early exit
                if(brackets.empty())
                {
                    return false;
                }
                char bracket = brackets.top();
                brackets.pop();
                //Check correspondence
                if(c == ')' && bracket != '(')
                {
                    return false;
                }
                if(c == '}' && bracket != '{')
                {
                    return false;
                }
                if(c == ']' && bracket != '[')
                {
                    return false;
                }
            }
        }
        //Ensure stack is empty by the end of string
        return brackets.empty();
    }
};
