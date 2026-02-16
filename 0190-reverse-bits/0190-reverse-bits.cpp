class Solution {
public:
    int reverseBits(int n) {
        if (n == 0) return 0;
        string s = "";
        s = bitset<32>(n).to_string();
        reverse(s.begin(),s.end());
        int ind = s.size();
        int num = ind;
        int sum = 0;
        for(int i=0;i<num;i++){
            if(s[i] == '1'){
                sum += pow(2,ind-1);
            }
            ind--;
        }
        return sum;
    }
};