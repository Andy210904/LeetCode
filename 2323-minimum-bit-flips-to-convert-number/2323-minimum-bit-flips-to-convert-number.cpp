class Solution {
public:
    string toBinary(int number) {
        string binary = "";
        while (number > 0) {
            binary = to_string(number % 2) + binary;
            number /= 2;
        }
        binary.insert(0, 32 - binary.length(), '0');
        return binary;
    }
    int minBitFlips(int start, int goal) {
        string star = toBinary(start);
        string go = toBinary(goal);
        int count=0;
        for(int i=0;i<star.size();i++){
            if(star[i] != go[i]){
                count++;
            }
        }
        return count;
    }
};