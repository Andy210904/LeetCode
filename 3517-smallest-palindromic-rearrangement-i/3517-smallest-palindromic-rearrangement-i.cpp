class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> alpha(26,0);
        for(int i=0;i<s.size();i++){
            alpha[s[i]-'a']++;
        }
        string res = "";
        char mid;
        bool isth = false;
        for(int i=0;i<26;i++){
            if(alpha[i] % 2 == 1){
                isth = true;
                mid = i+'a';
                res.append((alpha[i]-1)/2,i+'a');
            }
            else{
                res.append(alpha[i]/2,i+'a');
            }
        }
        string revres = res;
        reverse(revres.begin(), revres.end());
        res += revres;
        if(isth){
            int mid_ind = s.size() / 2;
            res.insert(res.begin() + mid_ind, mid);
        }
        return res;
    }
};