class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char maxDigit = '\0';
        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                maxDigit = max(maxDigit, num[i]);
            }
        }
        if (maxDigit == '\0') {
            return "";
        }
        return string(3, maxDigit);
    }
};
