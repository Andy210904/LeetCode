class Solution {
public:
    bool check(int n,int h,vector<int>& piles){
        int val = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] % n !=0){
                val += 1;
            }
            val += (piles[i]/n);
            if(val > h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] > max){
                max = piles[i];
            }
        }
        int left = 1;
        int right = max;
        int res = 0;
        while(left <= right){
            int mid = (left + right)/2;
            if(check(mid,h,piles)){
                right = mid-1;
                res = mid;
            }
            else{
                left = mid+1;
            }
        }
        return res;
    }
};