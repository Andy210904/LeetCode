class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int maxfreq = 0;
        while(right < s.size()){
            hash[s[right]-'A']++;
            maxfreq = max(maxfreq,hash[s[right]-'A']);
            if(right-left+1 - maxfreq > k){
                hash[s[left]-'A']--;
                left++;
            }
            if(right-left+1 - maxfreq <= k){
                maxlen = max(maxlen,right-left+1);
                right++;
            }
        }
        return maxlen;
    }
};