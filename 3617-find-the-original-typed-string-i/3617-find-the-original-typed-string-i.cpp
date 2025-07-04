class Solution {
public:
    int possibleStringCount(string word) {
        int same = 0;
        int count = 1;
        int n = word.size();
        for(int i = 0; i < n - 1; i++){
            if(word[i] == word[i + 1]){
                same++;
            }
            else{
                count += same;
                same = 0;
            }
        }
        count += same;
        return count;
    }
};