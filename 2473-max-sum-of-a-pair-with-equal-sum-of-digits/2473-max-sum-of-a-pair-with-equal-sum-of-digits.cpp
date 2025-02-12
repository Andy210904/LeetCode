class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> temp;
        int max = -1;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            int temp1 = nums[i];
            while(temp1!=0){
                int x = temp1 % 10;
                temp1 = temp1/10;
                sum += x;
            }
            if(temp.find(sum) != temp.end()){
                max = std::max(max,temp[sum] + nums[i]);
                temp[sum] = std::max(temp[sum],nums[i]);
            }
            else{
                temp[sum] = nums[i];
            }
            
        }
        return max;
    }
};