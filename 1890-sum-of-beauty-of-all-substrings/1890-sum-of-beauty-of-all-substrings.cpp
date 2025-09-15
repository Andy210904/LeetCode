class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            freq[s[i] - 'a']++;
            for(int j=i+1;j<n;j++){
                freq[s[j]-'a']++;
                int max_freq = 1;
                int min_freq = INT_MAX;
                for(int k=0;k<26;k++){
                    int temp = freq[k];
                    if(temp > 0 && max_freq < temp){
                        max_freq = temp;
                    }
                    if(temp > 0 && min_freq > temp){
                        min_freq = temp;
                    }
                }
                res += (max_freq - min_freq);
            }
        }
        return res;
    }
};