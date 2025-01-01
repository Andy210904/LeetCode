class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0; 
        for (char c : s) {
            if (c == '1'){
                totalOnes++;
            }
        }
        int maxScore = 0;
        int zeros = 0, ones = totalOnes;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }
            maxScore = max(maxScore, zeros + ones);
        }
        return maxScore;
    }
};