class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int longest = 0;
        int even = 0;
        int odd = 0;
        unordered_map<int,int> distinct;
        for(int i=0;i<nums.size();i++){
            even = 0;
            odd = 0;
            distinct.clear();
            distinct[nums[i]] = 1;
            if(nums[i] % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
            for(int j=i+1;j<nums.size();j++){
                if(nums[j] % 2==0 && distinct.find(nums[j]) == distinct.end()){
                    even++;
                }
                else if (nums[j] % 2 !=0 && distinct.find(nums[j]) == distinct.end()){
                    odd++;
                }
                distinct[nums[j]] = 1;
                if(even == odd){
                    longest = max(longest,j-i+1);
                }
            }
        }
        return longest;
    }
};