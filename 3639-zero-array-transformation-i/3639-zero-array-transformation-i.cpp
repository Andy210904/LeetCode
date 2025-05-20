class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> dummy(n+1,0);
        for(int i=0;i<queries.size();i++){
            dummy[queries[i][0]]++;
            dummy[queries[i][1]+1]--;
        }
        for(int i=1;i<nums.size();i++){
            dummy[i] += dummy[i-1];
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > dummy[i]){
                return false;
            }
        }
        return true;
    }
};