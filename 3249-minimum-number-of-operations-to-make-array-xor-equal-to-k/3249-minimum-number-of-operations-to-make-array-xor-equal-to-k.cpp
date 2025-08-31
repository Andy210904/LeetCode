class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans ^= nums[i];
        }
        bitset<32> b(ans);
        bitset<32> need(k);
        int res = 0;
        for(int i=0;i<32;i++){
            if(b[i] != need[i]){
                res++;
            }
        }
        return res;
    }
};