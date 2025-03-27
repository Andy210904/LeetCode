class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>temp;
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
        }
        int dom = 0;
        int right_count = 0;
        int left_count = 0;
        for(auto pair : temp){
            if(pair.second > nums.size()/2){
                dom = pair.first;
                right_count = pair.second;
                break;
            }
        }
        if(nums[0] == dom){
            right_count -= 1;
            left_count += 1;
        }
        int size1 = 1;
        int size2 = nums.size()-1;
        for(int i=1;i<nums.size();i++){
            if(left_count > size1/2 && right_count > size2/2){
                return i-1;
            }
            if(nums[i]==dom){
                left_count++;
                size1++;
                right_count--;
                size2--;
            }
            else{
                size1++;
                size2--;
            }
        }
        return -1;
    }
};