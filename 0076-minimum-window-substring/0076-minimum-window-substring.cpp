class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int n = s.size();
        int m = t.size();
        int right = 0;
        unordered_map<char,int> temp;
        for(char ch : t){
            temp[ch]++;
        }
        int count = 0;
        int start = -1;
        int minlen = INT_MAX;
        while(right<n){
            if(temp[s[right]] > 0){
                count++;
            }
            temp[s[right]]--;
            while(count == m){
                if(minlen > right-left+1){
                    minlen = right-left+1;
                    start = left;
                }
                temp[s[left]]++;
                if(temp[s[left]]>0){
                    count--;
                }
                left++;
            }
            right++;
        }
        if(start!=-1){
            return s.substr(start,minlen);
        }
        else{
            return "";
        }
    }
};