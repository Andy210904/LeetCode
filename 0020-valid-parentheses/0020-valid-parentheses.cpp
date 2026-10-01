class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n % 2 != 0) {
            return false;
        }
        
        stack<char> charStack;
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                charStack.push(c);
            } else {
                if (charStack.empty()) {
                    return false; 
                }
                char topChar = charStack.top();
                charStack.pop();
                if ((c == ')' && topChar != '(') ||
                    (c == ']' && topChar != '[') ||
                    (c == '}' && topChar != '{')) {
                    return false; 
                }
            }
        }
        return charStack.empty();
    }
};
