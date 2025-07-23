class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lower = -1;
        int x = target;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            cout<<mid<<endl;
            if (nums[mid] >= x){
                lower = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        if(lower == -1){
            if(nums[nums.size()-1] < target){
                return nums.size();
            }   
        }
        return lower;
    }
};