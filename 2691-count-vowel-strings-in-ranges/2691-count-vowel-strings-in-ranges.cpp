class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> temp;
        for (int i = 0; i < words.size(); i++) {
            int left = 0;
            int right = words[i].size() - 1;
            auto isVowel = [](char ch) {
                ch = tolower(ch); 
                return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
            };
            if (isVowel(words[i][left]) && isVowel(words[i][right])) {
                temp.push_back(1);
            }
            else{
                temp.push_back(0);
            }
        }
        vector<int> res;
        for(int i=1;i<temp.size();i++){
            temp[i] += temp[i-1];
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]-1 < 0){
                res.push_back(temp[queries[i][1]]);
            }
            else{
                res.push_back(temp[queries[i][1]] - temp[queries[i][0]-1]);
            }
        }
        return res;
    }
};