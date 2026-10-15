class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<nums.size();i++){
            set<int> temp;
            int count = 0;
            for(int j=i;j<nums.size();j++){
                if(temp.find(nums[j]) == temp.end()){
                    temp.insert(nums[j]);
                    count++;
                }
                result += (count*count);
            }
        }
        return result;
    }
};