class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> temp;
        stringstream ss(s1);
        string word;
        vector<string> ans;
        vector<string> wordArray;
        stringstream sa(s2);
        vector<string> wordArray1;
        while (ss >> word) {
            wordArray.push_back(word);
        }
        while (sa >> word) {
            wordArray1.push_back(word);
        }
        for(int i=0;i<wordArray.size();i++){
            temp[wordArray[i]]++;
        }
        for(int i=0;i<wordArray1.size();i++){
            temp[wordArray1[i]]++;
        }
        for(const auto pair : temp){
            if(pair.second < 2){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};