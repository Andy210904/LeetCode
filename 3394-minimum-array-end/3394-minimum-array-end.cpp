class Solution {
public:
    string to_binary(long long n) {
        string binary = "";
        for (long long i = 63; i >= 0; i--) {
            binary += (n & (1LL << i)) ? '1' : '0';
        }
        return binary;
    }
    long long to_integer(string binary) {
        long long result = 0;
        for (char bit : binary) {
            result = (result << 1) + (bit - '0');
        }
        return result;
    }   
    long long minEnd(int n, int x) {
        string temp = to_binary(n-1);
        string ans = to_binary(x);
        int j = 63;
        for(int i=63;i>=0;i--){
            if(ans[i]=='0'){
                ans[i] = temp[j];
                j--;
            }
        }
        return to_integer(ans);
    }
};