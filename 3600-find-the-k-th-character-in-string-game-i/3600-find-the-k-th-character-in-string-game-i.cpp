class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        while(res.size() < k){
            int n = res.size();
            for(int i=0;i<n;i++){
                res += (char)((res[i] - 'a' + 1) % 26 + 'a');
            }
        }
        return res[k-1];
    }
};