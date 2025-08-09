class Solution {
public:
    int numberOfSubstrings(string s) {
        // intution think of subarrays ending at a particular index and count all the subarrays before that index
        vector<int> seen(3,-1);
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            seen[s[i] - 'a'] = i;
            cnt = cnt + 1+min({seen[0],seen[1],seen[2]});
        }
        return cnt;
    }
};