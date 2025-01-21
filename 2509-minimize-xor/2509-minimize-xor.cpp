class Solution {
public:
    string toFixed32BitBinary(int number) {
        return bitset<32>(number).to_string();
    }
    int binaryStringToInteger(const string& binaryString) {
        return bitset<32>(binaryString).to_ulong(); 
    }
    int minimizeXor(int num1, int num2) {
        int count2 = 0;
        string b_num2 = toFixed32BitBinary(num2);
        string b_num1 = toFixed32BitBinary(num1);
        for(int i=0;i<b_num2.size();i++){
            if(b_num2[i] == '1'){
                count2++;
            }
        }
        string binaryString(32, '0');
        for(int i=0;i<32;i++){
            if(b_num1[i] == '1'){
                binaryString[i] = '1';
                count2--;
            }
            if(count2 == 0){
                break;
            }
        }
        int index = 31;
        while(count2 != 0){
            if(binaryString[index] != '1'){
                binaryString[index] = '1';
                count2--;
            }
            index--;
        }
        int result = binaryStringToInteger(binaryString);
        return result;
    }
};