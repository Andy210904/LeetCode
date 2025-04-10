class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> temp;
        for(int i=0;i<nums.size();i++){
            temp.insert(nums[i]);
            if(nums[i] < k){
                return -1;
            }
        }
        int count = 0;
        for(int c : temp){
            if(c==k){
                continue;
            }
            else{
                count++;
            }
        }
        return count;

    }
};