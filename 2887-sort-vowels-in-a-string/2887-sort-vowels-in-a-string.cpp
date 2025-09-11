class Solution {
public:
    string sortVowels(string s) {
        string vowel = "";
        string final = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
                s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowel += s[i];
            }
        }
        sort(vowel.begin(), vowel.end());
        int vowelIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
                s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                final += vowel[vowelIndex++];
            } else {
                final += s[i];
            }
        }

        return final;
    }
};