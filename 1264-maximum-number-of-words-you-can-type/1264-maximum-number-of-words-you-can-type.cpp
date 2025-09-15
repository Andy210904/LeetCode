class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        unordered_set<char> freq;
        for(int i=0;i<brokenLetters.size();i++){
            freq.insert(brokenLetters[i]);
        }
        vector<string> words;
        int n = text.size();
        string temp = "";
        for(int i=0;i<n;i++){
            if(text[i]!=' '){
                temp+=text[i];
            }
            else{
                words.push_back(temp);
                temp="";
            }
        }
        words.push_back(temp);
        n = words.size();
        for(int i=0;i<n;i++){
            for(char c : words[i]){
                if(freq.find(c) != freq.end()){
                    res++;
                    break;
                }
            }
        }
        return n-res;
    }
};