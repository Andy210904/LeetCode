class Solution {
public:
    bool hasAlternatingBits(int n) {
        string bin = "";
        while(n > 0){
            int x = n % 2;
            n = n/2;
            bin += to_string(x);
        }
        char fir = bin[0];
        for(int i=1;i<bin.size();i++){
            if(bin[i] == fir){
                return false;
            }
            fir = bin[i];
        }
        return true;
    }
};