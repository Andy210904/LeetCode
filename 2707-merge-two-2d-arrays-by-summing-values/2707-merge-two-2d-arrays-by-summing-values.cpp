class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int first = 0;
        int sec = 0;
        vector<vector<int>> res;
        while(first < nums1.size() && sec < nums2.size()){
            if(nums1[first][0] == nums2[sec][0]){
                nums1[first][1] += nums2[sec][1];
                res.push_back(nums1[first]);
                first++;
                sec++;
            }
            else if(nums1[first][0] < nums2[sec][0]){
                res.push_back(nums1[first]);
                first++;
            }
            else{
                res.push_back(nums2[sec]);
                sec++;
            }
        }
        while(first < nums1.size()){
            res.push_back(nums1[first]);
            first++;
        }
        while(sec < nums2.size()){
            res.push_back(nums2[sec]);
            sec++;
        }
        return res;
    }
};