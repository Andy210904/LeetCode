class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> temp;
        for(int i=0;i<strs.size();i++){
            vector<char> charVec(strs[i].begin(), strs[i].end());
            charVec.push_back('\0');
            sort(charVec.begin(),charVec.end());
            string str(charVec.begin(),charVec.end());
            temp[str].push_back(strs[i]);
        }
        for(auto pair : temp){
            res.push_back(pair.second);
        }
        return res;
    }
};