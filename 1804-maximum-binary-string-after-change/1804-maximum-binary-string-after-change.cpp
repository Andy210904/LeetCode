class Solution {
public:
    string maximumBinaryString(string binary) {
        int cnt = 0;
        int n = binary.size();
        string ans(n,'1');
        for(int i=0;i<n;i++){
            if(binary[i] == '0'){
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            if(binary[i] == '0'){
                ans[i+cnt-1] = '0';
                return ans;
            }
        }
        return ans;
    }
};