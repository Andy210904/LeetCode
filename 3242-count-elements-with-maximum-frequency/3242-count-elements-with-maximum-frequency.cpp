class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int max = 1;
        int sum=0;
        for(const auto& pair:count){
            if(pair.second>max){
                max = pair.second;
            }
        }
        for(const auto& pair:count){
            if(pair.second==max){
                sum = sum+max;
            }
        }
        return sum;
    }
};