class Solution {
public:
    int possibleStringCount(string word) {
        char fir = word[0];
        int n = word.size();
        int res = 0;
        for(int i=1;i<n;i++){
            int count = 0;
            while(i<n && word[i] == fir){
                count++;
                i++;
            }
            fir = word[i];
            res += count;
        }
        return res+1;
    }
};