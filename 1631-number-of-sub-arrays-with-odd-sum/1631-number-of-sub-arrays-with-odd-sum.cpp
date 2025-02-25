class Solution {
public:
    int MOD = pow(10,9) + 7;
    int numOfSubarrays(vector<int>& arr) {
        int res = 0;
        int ev = 1;
        int od = 0;
        int pref = 0;
        for(int i=0;i<arr.size();i++){
            pref += arr[i];
            if(pref % 2 == 1){
                (res += ev);
                od++;
            }
            else{
                (res += od);
                ev++;
            }
            res = res % MOD;
        }
        return res ;
    }
};