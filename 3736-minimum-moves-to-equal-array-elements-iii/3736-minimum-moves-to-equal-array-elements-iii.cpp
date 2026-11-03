class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max1 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            max1 = max(max1,nums[i]);
        }
        int moves = 0;
        for(int i=0;i<nums.size();i++){
            moves += max1-nums[i];
        }
        return moves;
    }
};