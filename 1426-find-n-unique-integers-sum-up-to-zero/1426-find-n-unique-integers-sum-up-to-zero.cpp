class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n,0);
        if(n == 1){
            return {0};
        }
        int i = -(n/2);
        int ind = 0;
        if(n % 2 == 0){
            while(ind != n){
                if(i!=0){
                    res[ind] = i;
                    ind++;
                }
                i++;
            }
        }
        else{
            while(ind != n){
                res[ind] = i;
                i++;
                ind++;
            }
        }
        return res;
    }
};