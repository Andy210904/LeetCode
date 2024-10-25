class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> temp;
        for(int i = 0; i < folder.size(); i++){
            temp.insert(folder[i]);
        }
        vector<string> res;
        for (string &s : folder) {
            bool pres = false;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '/') {
                    string tem = s.substr(0, i); 
                    if (temp.find(tem) != temp.end()) {
                        pres = true;
                        break;
                    }
                }
            }
            if (pres == false) {
                res.push_back(s);
            }
        }
        return res;
    }
};
