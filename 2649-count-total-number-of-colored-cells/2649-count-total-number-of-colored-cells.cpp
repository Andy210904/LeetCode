class Solution {
public:
    long long coloredCells(int n) {
        long long mul = 4;
        if(n==1){
            return 1;
        }
        long long res = 0;
        for(int i=1;i<n;i++){
            res += (mul * i);
        }
        return res+1;   
    }
};