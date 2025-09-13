class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<char> temp;
        temp.insert('a');
        temp.insert('e');
        temp.insert('i');
        temp.insert('o');
        temp.insert('u');
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i] -'a']++;
        }
        int max_c = 0;
        int max_v = 0;
        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                if(temp.find(i + 'a') != temp.end()){
                    max_v = max(max_v,freq[i]);
                }
                else{
                    max_c = max(max_c,freq[i]);
                }
            }
        }
        return max_v+max_c;
    }
};