class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int count1 = nums1.size();
        int count2 = nums2.size();
        int result = 0;
        if(count1 %2){
            for(int num : nums2){
                result = result ^ num;
            }
        }
        if(count2 %2){
            for(int num : nums1){
                result = result ^ num;
            }
        }
        return result;
        
    }
};