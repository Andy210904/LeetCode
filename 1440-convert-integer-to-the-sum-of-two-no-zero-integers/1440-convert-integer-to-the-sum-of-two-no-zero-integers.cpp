class Solution {
public:
    bool haszeo(int a){
        while(a!=0){
            int x = a % 10;
            a = a/10;
            if(x == 0){
                return true;
            }
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n-1;
        while(true){
            if(!haszeo(a) && !haszeo(b)){
                return {a,b};
            }
            a++;
            b--;
        }
    }
};