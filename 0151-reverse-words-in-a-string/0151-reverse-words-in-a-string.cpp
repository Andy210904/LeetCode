class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int ind = s.size()-1;
        while(ind >= 0){
            string temp ="";
            if(s[ind]==' '){
                ind--;
                continue;
            }
            while(ind >=0 && isalnum(s[ind])){
                temp += s[ind];
                ind--;
            }
            reverse(temp.begin(),temp.end());
            res += temp;
            res += " ";
        }
        return res.substr(0,res.size()-1);
    }
};