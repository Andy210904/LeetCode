class Solution {
public:
    bool prefix(string str1,string str2){
        if(str1.size() < str2.size()){
            return false;
        }
        if(str1.substr(0,str2.size()) == str2){
            return true;
        }
        return false;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(int i=0;i<words.size();i++){
            if(prefix(words[i],pref)){
                count++;
            }
        }
        return count;
    }
};