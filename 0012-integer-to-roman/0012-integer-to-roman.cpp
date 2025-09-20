class Solution {
public:
    string intToRoman(int num) {
        vector<string> ones = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string> tens = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> hund = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> thou = {"","M","MM","MMM"};
        string res = "";
        res += thou[num / 1000];
        num = num % 1000;
        res += hund[num /100];
        num = num % 100;
        res += tens[num/10];
        num = num%10;
        res += ones[num];
        return res;
    }
};