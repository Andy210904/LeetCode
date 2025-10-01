class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int rem = 0;
        while(numBottles+rem >=  numExchange){
            int total = numBottles + rem;          
            int newFull = total / numExchange;     
            res += newFull;                       
            rem = total % numExchange;             
            numBottles = newFull;
        }
        return res;
    }
};