class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> temp;
        int n = s.size();
        int i = 0;
        string res = "";
        while(i < n){
            if(temp.empty() && s[i] == '('){
                temp.push(s[i]);
            }
            else if(s[i] == ')' && temp.top() == '(' && temp.size() == 1){
                temp.pop();
            }
            else if(s[i] == ')' && temp.top() == '('){
                temp.pop();
                res += s[i];
            }
            else{
                temp.push(s[i]);
                res += s[i];
            }
            i++;
        }
        return res;
    }
};