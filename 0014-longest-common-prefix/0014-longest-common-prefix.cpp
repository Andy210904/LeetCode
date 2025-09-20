class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        int n = min(first.size(),last.size());
        int ind = 0;
        string res = "";
        while(ind < n){
            char c = first[ind];
            char c1 = last[ind];
            if(c == c1){
                res += c;
                ind++;
            }
            else{
                break;
            }
        }
        return res;
    }
};