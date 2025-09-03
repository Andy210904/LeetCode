class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(temp.find(nums[i]) != temp.end()){
                if(abs(i-temp[nums[i]]) <= k){
                    return true;
                }
            }
            temp[nums[i]] = i;
        }
        return false;
    }
};