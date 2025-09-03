class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> temp1;
        while(true){
            int temp=0;
            while(n!=0){
                int x = n % 10;
                n = n/10;
                temp += (pow(x,2));
            }
            if(temp == 1){
                return true;
            }
            if(temp1.find(temp) != temp1.end()){
                return false;
            }
            temp1[temp] = 1;
            n = temp;
        }
        return true;
    }
};