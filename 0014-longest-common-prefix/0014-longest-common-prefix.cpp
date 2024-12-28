class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  
        string res = "";
        int index = 0;
        while (true) {
            char c = 0;
            for (int i = 0; i < strs.size(); i++) {
                if (index >= strs[i].size()) return res;
                if (i == 0) {
                    c = strs[i][index];  
                } else if (strs[i][index] != c) {
                    return res; 
                }
            }
            res += c;  
            index++;
        }
        return res;  
    }
};
