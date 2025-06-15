class Solution {
public:
    int maxDiff(int num) {
        string num1 = to_string(num);
        string num2 = to_string(num);
        bool digit_found = false;
        bool digit_found1 = false;
        bool isfirst = true;
        char digit = '9';
        for(int i=0;i<num1.size();i++){
            if(num1[i] =='9'){
                continue;
            }
            else if(!digit_found){
                digit_found = true;
                digit = num1[i];
            }
            if(num1[i] == digit){
                num1[i] = '9';
            }
        }
        for(int i=0;i<num2.size();i++){
            if(num2[i] =='1' || num2[i] =='0'){
                continue;
            }
            else if(!digit_found1){
                digit_found1 = true;
                digit = num2[i];
                if(i!=0){
                    isfirst = false;
                }
            }
            if(num2[i] == digit && isfirst){
                num2[i] = '1';
            }
            else if(num2[i] == digit && !isfirst){
                num2[i] = '0';
            }
        }
        return stoi(num1) - stoi(num2);
    }
};