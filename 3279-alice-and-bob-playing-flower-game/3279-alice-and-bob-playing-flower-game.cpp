class Solution {
public:
    long long flowerGame(int n, int m) {
        int odd_m = 0;
        int even_m = 0;
        for(int i=1;i<=m;i++){
            if(i % 2==0){
                even_m++;
            }
            else{
                odd_m++;
            }
        }
        long long res = 0;
        for(int i=1;i<=n;i++){
            if(i % 2 == 0){
                res += odd_m;
            }
            else{
                res += even_m;
            }
        }
        return res;
    }
};