class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        for(int i=0;i<nums.size();i++){
            res += nums[i];
        }
        vector<int> delta;
        for(int i=0;i<nums.size();i++){
            delta.push_back((nums[i] ^ k) - nums[i]);
        }
        sort(delta.rbegin(),delta.rend());
        long long sum = res;
        if(delta.size() % 2 == 0){
            for(int i=0;i<delta.size();i=i+2){
                sum = sum + delta[i] + delta[i+1];
                res = std::max(sum,res);
                if(sum < res){
                    break;
                }
            }
        }
        else{
            for(int i=0;i<delta.size()-1;i=i+2){
                sum = sum + delta[i] + delta[i+1];
                res = max(sum,res);
                if(sum < res){
                    break;
                }
            }
        }
        return res;
    }
};