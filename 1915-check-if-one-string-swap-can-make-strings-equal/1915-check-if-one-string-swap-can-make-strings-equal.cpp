class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> alpha(26,0);
        for(int i=0;i<s1.size();i++){
            alpha[s1[i] - 'a']++;
        }
        for(int i=0;i<s2.size();i++){
            alpha[s2[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(alpha[i] != 0){
                return false;
            }
        }
        return true;

    }
};