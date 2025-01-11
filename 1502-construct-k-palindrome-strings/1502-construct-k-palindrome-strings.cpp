class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k){
            return false;
        }
        vector<int> alp(26,0);
        for(int i=0;i<s.size();i++){
            alp[s[i] - 'a']++;
        }
        int count = 0;
        for(int i=0;i<26;i++){
            if(alp[i] % 2 ==1){
                count++;
            }
        }
        if(count > k){
            return false;
        }
        return true;
    }
};