class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        res.push_back(words[0]);
        int check = 0;
        check += groups[0];
        for(int i=1;i<groups.size();i++){
            if(check == 1 && groups[i] == 0){
                res.push_back(words[i]);
                check -= 1;
            }
            if(check == 0 && groups[i] == 1){
                res.push_back(words[i]);
                check += 1;
            }
        }
        return res;
    }
};