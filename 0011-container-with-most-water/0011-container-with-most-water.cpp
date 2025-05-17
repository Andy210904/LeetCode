class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res = INT_MIN;
        while(left <= right){
            if(height[left] < height[right]){
                int area = (right - left)*(height[left]);
                res = max(res,area);
                left++;
            }
            else{
                int area = (right - left)*(height[right]);
                res = max(res,area);
                right--;
            }
        }
        return res;
    }
};