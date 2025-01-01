class Solution {
public:
    int maxScore(string s) {
        int one = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                one++;
            }
        }
        int score = INT_MIN;
        int zero = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == '0'){
                zero++;
                score = max(score,zero+one);
            }
            else{
                one--;
                score = max(score,zero+one);
            }
        }
        return score;
    }
};