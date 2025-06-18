class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size()/3;
        vector<vector<int>> result(n, vector<int>(3, 0));
        sort(nums.begin(),nums.end());
        int l=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                result[i][j]=nums[l];
                l++;
            }
        }
        for(int i=0;i<n;i++){
            auto maxElement = max_element(result[i].begin(), result[i].end());
            auto minElement = min_element(result[i].begin(), result[i].end());
            if(*maxElement - *minElement <= k){
                continue;
            }
            else{
                result.clear();
                break;
            }
        }
        return result;
    }
};