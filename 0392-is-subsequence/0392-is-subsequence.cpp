class Solution {
public:
    bool isSubsequence(string s, string t) {
        int first = 0;
        int last = 0;
        int n = s.size();
        int m = t.size();
        while(first < n && last < m){
            if(s[first] == t[last]){
                first++;
                last++;
            }
            else{
                last++;
            }
        }
        if(first == n){
            return true;
        }
        return false;
    }
};