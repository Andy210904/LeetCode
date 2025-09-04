class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts;
        string temp = "";
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (!temp.empty()) {
                    parts.push_back(temp);
                    temp.clear();
                }
            } else {
                temp += path[i];
            }
        }
        stack<string> st;
        for (auto &p : parts) {
            if (p == "." ) {
                continue;
            } else if (p == "..") {
                if (!st.empty()) {
                    st.pop(); 
                }
            } else {
                st.push(p); 
            }
        }
        string res = "";
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res.empty() ? "/" : res;
    }
};
