class Solution {
public:
    bool recurse(vector<int>& nums, int front, int back, int p1, int p2, bool turn) {
        if (front > back) {
            return p1 >= p2;
        }
        if (turn) { 
            return recurse(nums, front + 1, back, p1 + nums[front], p2, false) ||
                   recurse(nums, front, back - 1, p1 + nums[back], p2, false);
        } else { 
            return recurse(nums, front + 1, back, p1, p2 + nums[front], true) &&
                   recurse(nums, front, back - 1, p1, p2 + nums[back], true);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return recurse(nums, 0, nums.size() - 1, 0, 0, true);
    }
};