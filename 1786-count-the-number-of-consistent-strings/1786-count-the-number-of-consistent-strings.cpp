class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> temp;
        for(int i=0;i<allowed.size();i++){
            temp.insert(allowed[i]);
        }
        int count = 0;
        for(int i=0;i<words.size();i++){
            int tem = 0;
            for(int j=0;j<words[i].size();j++){
                if(temp.find(words[i][j]) == temp.end()){
                    break;
                }
                else{
                    tem++;
                }
            }
            if(tem == words[i].size()){
                count++;
            }
        }
        return count;
    }
};