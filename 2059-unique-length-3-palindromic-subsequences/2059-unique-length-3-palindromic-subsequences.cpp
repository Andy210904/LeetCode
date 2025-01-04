class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> alpha(26,0);
        for(int i=0;i<s.size();i++){
            alpha[s[i] - 'a']++;
        }
        int count = 0;
        for(int i=0;i<26;i++){
            int left = 0;
            int right = s.size()-1;
            unordered_set<char> temp;
            if(alpha[i] > 1){
                while(s[left] != (i+'a')){
                    left++;
                }
                while(s[right] != (i+'a')){
                    right--;
                }
                for(int j=left+1;j<right;j++){
                    if(temp.find(s[j]) == temp.end()){
                        temp.insert(s[j]);
                        count++;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        return count;
    }
};