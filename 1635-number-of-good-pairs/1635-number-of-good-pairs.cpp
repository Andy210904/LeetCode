class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> temp;
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
        }
        int count = 0;
        for(auto pair : temp){
            if(pair.second > 1){
                count += ((pair.second)*(pair.second - 1))/2;
            }
        }
        return count;
    }
};