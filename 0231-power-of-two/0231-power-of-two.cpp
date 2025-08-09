class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0){
            return false;
        }
        int n1 = sqrt(n);
        for(int i=0;i<=n1+1;i++){
            if(n == pow(2,i)){
                return true;
            }
        }
        return false;
    }
};