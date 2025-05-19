class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_map<int,int> temp;
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
        }
        for(auto pair : temp){
            if(pair.second == 3){
                return "equilateral";
            }
            if(pair.second == 2){
                if(nums[0]+nums[1] > nums[2] && nums[1]+nums[2] > nums[0] && nums[0] + nums[2] > nums[1]){
                    return "isosceles";
                }
            }
        }
        if(nums[0]+nums[1] > nums[2] && nums[1]+nums[2] > nums[0] && nums[0] + nums[2] > nums[1]){
            return "scalene";
        }
        return "none";
    }
};