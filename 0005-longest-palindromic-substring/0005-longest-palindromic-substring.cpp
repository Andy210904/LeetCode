class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        string res = "";
        for(int i=0;i<s.size();i++){
            //odd length
            int l = i; int r = i;
            while(l>=0 && r <n && s[l] == s[r]){
                if(maxlen < r-l+1){
                    maxlen = r-l+1;
                    res = s.substr(l,maxlen);
                }
                l--;
                r++;
            }
            //even length
            l = i;r=i+1;
            while(l>=0 && r <n && s[l] == s[r]){
                if(maxlen < r-l+1){
                    maxlen = r-l+1;
                    res = s.substr(l,maxlen);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};